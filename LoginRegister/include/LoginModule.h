#pragma once

#include <linux/limits.h>
#include <memory>
#include <wfrest/HttpServer.h>
#include <workflow/WFFacilities.h>

using namespace wfrest;

class LoginModel {
public:
  LoginModel(HttpServer *httpserver);
  ~LoginModel();
  bool start(); // 开启登录服务模块
private:
  bool LoginHandle(const HttpReq *req, HttpResp *resp);

private:
  HttpServer *phttpserver;
};