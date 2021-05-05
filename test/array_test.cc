#include <stdlib.h>
#include <stdlib.h>  /* abs */
#include "napi.h"

using namespace Napi;

namespace {

void ArrayAbs(const Napi::CallbackInfo& info) {
  Buffer<char> buf = info[0].As<Buffer<char>>();
  int *arr = reinterpret_cast<int *>(buf.Data());
  int length = info[1].As<Number>();

  for (int i = 0; i < length; i++) {
    *(arr + i) = abs(arr[i]);
  }
}

Object Initialize(Env env, Object exports) {

  exports.Set("arrayAbs", Function::New(env, ArrayAbs));

  return exports;
}

} // anonymous namespace

NODE_API_MODULE(array_tests, Initialize);
