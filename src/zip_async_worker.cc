// Copyright 2014 Haojian Wu. All rights reserved.
// Use of this source code is governed by MIT license that can be found in the
// LICENSE file.

#include "zip_async_worker.h"

#include "zip.h"

namespace zip {

ZipAsyncWorker::ZipAsyncWorker(const std::string& src_dir, const std::string& dest_file, Nan::Callback* callback, const std::string& password): 
     Nan::AsyncWorker(callback), 
     buf(NULL),
     buf_size(0),
     src_dir(src_dir), 
     dest_file(dest_file),
     password(password)
{
}

ZipAsyncWorker::ZipAsyncWorker(void* buf, const size_t buf_size, const std::string& relative_path, const std::string& dest_file, Nan::Callback *callback, const std::string& password) :
     Nan::AsyncWorker(callback),
     buf(buf),
     buf_size(buf_size),
     dest_file(dest_file),
     relative_path(relative_path),
     password(password)
{
}

void ZipAsyncWorker::Execute() {
  std::string error_message;
  if(buf == NULL) {
bool Zip(const std::string& src_dir, const std::string& dest_file, std::string* error);
      if (!Zip(src_dir, dest_file, &error_message)){
        SetErrorMessage(error_message.c_str());
      }
  } else {
      if(!Zip(buf, buf_size, relative_path, dest_file, password.c_str(), &error_message)){
        SetErrorMessage(error_message.c_str());
      }
  }
}

UnzipAsyncWorker::UnzipAsyncWorker(const std::string& zip_file, const std::string& dest_dir, Nan::Callback* callback, const std::string& password)
 : Nan::AsyncWorker(callback), 
   zip_file(zip_file), 
   dest_dir(dest_dir), 
   password(password)
{
}

void UnzipAsyncWorker::Execute() {
  std::string error_message;
  if(password.size() > 0) {
      if (!Unzip(zip_file, dest_dir, password.c_str(), &error_message)){
        SetErrorMessage(error_message.c_str());
      }
  } else {
      if (!Unzip(zip_file, dest_dir, &error_message)){
        SetErrorMessage(error_message.c_str());
      }
  }
}

}  // namespace zip
