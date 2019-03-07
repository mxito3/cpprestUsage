from flask import Flask, render_template, url_for, request, redirect, flash, request, session, make_response, jsonify

import uuid

app = Flask(__name__)
app.secret_key = bytes(str(uuid.uuid4()), 'utf-8')



@app.route('/')
def index():
    response={}
    response['userName']="yapie"
    response['password']="yapiePassword"
    return jsonify(response)
if __name__ == "__main__":
    app.run(host='0.0.0.0', threaded=True, debug=True, port=8080)