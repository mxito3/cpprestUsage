#include <cpprest/http_client.h>
#include <cpprest/filestream.h>
#include "sstream"
using namespace utility;              // Common utilities like string conversions
using namespace web;                  // Common features like URIs.
using namespace web::http;            // Common HTTP functionality
using namespace web::http::client;    // HTTP client features
using namespace concurrency::streams; // Asynchronous streams

int main(int argc, char *argv[])
{
   http_client clientWL(U("http://localhost:8080/arrayTest"));

   auto task = clientWL.request(methods::GET);
   while (!task.is_done())
      ;
   http_response resp1 = task.get();
   // in string
   // auto response_string = resp1.extract_string().get();
   // std::cout << response_string << std::endl; // Will print it to stdout
   
   
   // in jsonstring
   auto response_json= resp1.extract_json().get();
   std::cout<<response_json;
   //获取userInfo字段
   if(response_json.has_array_field(U("userInfo"))) //判断有没有password字段
   {
      auto userInfo=response_json.at(U("userInfo"));
      auto userName=userInfo.at(0);
      auto password=userInfo.at(1);
      std::cout<<"userName is"<<userName<<std::endl;
      std::cout<<"password is"<<password<<std::endl;
   }
   
   return 0;
}