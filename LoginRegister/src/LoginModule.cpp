#include "LoginModule.h"
#include <wfrest/HttpServer.h>

LoginModel::LoginModel(HttpServer *httpserver) { phttpserver = httpserver; }

LoginModel::~LoginModel() { phttpserver = nullptr; }

bool LoginModel::start() {
  phttpserver->POST("/usr/login", [this](const HttpReq *req, HttpResp *resp) {
    this->LoginHandle(req, resp);
  });
  return true;
}

bool LoginModel::LoginHandle(const HttpReq *req, HttpResp *resp) {
  // URLENCODED类型的请求体
  if (req->content_type() == APPLICATION_URLENCODED) {
    auto formKV = req->form_kv();
    std::string username = formKV["username"];
    std::string password = formKV["password"];
  }
  return true;
}