// Copyright 2014 Haojian Wu. All rights reserved.
// Use of this source code is governed by MIT license that can be found in the
// LICENSE file.

#ifndef SRC_ZIP_WORKER_H_
#define SRC_ZIP_WORKER_H_

#include <string>

#include "nan.h"

namespace zip {

class ZipAsyncWorker : public Nan::AsyncWorker {
 public:
  ZipAsyncWorker(const std::string& src_dir, const std::string& dest_file, Nan::Callback* callback, const std::string& password = "");
  ZipAsyncWorker(void* buf, const size_t buf_size, const std::string& relative_path, const std::string& dest_file, Nan::Callback *callback, const std::string& password = "");

  // Override Nan::AsyncWorker methods.
  virtual void Execute();
 private:
  void* buf;
  const size_t buf_size;
  const std::string src_dir;
  const std::string dest_file;
  const std::string relative_path;
  const std::string password;
};

class UnzipAsyncWorker : public Nan::AsyncWorker {
 public:
  UnzipAsyncWorker(const std::string& zip_file, const std::string& dest_dir, Nan::Callback* callback, const std::string& password = "");

  // Override Nan::AsyncWorker methods.
  virtual void Execute();
 private:
  const std::string zip_file;
  const std::string dest_dir;
  const std::string password;
};

}  // namespace zip

#endif  // SRC_ZIP_WORKER_H_
