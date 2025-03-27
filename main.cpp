#include <iostream>
#include <signal.h>
#include <wfrest/HttpServer.h>
#include <workflow/WFFacilities.h>
#include "LoginModule.h"

static WFFacilities::WaitGroup wait_group(1);

void sighandler(int num) {
  printf("sig %d is coming\n", num);
  wait_group.done();
}

int main() {
  using std::string;
  signal(SIGINT, sighandler);
  using namespace wfrest;
  HttpServer httpserver;

  // 创建一个LoginModel对象
  LoginModel loginModel(&httpserver);
  // 启动LoginModel对象
  loginModel.start();

  // 启动服务器监听8888端口
  if (httpserver.track().start(1235) == 0) {
    // 列出当前服务器上部署的服务
    httpserver.list_routes();
    wait_group.wait();
    httpserver.stop();
  } else {
    printf("HttpServer start failed.\n");
  }

  return 0;
}