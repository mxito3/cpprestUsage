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
   http_client clientWL(U("http://localhost:8080"));

   auto task = clientWL.request(methods::GET);
   while (!task.is_done())
      ;
   http_response resp1 = task.get();
   // in string
   // auto response_string = resp1.extract_string().get();
   // std::cout << response_string << std::endl; // Will print it to stdout
   
   
   // in jsonstring
   auto response_json= resp1.extract_json().get();
   // std::cout<<response_json;
   //获取密码字段
   if(response_json.has_string_field(U("password"))) //判断有没有password字段
   {
      auto password=response_json.at(U("password"));
      std::cout<<"password is"<<password<<std::endl;
   }
   //获取userName
   if(response_json.has_string_field(U("userName")))
   {
      auto userName=response_json.at(U("userName"));
      std::cout<<"userName is"<<userName<<std::endl;
   
   }
   return 0;
}