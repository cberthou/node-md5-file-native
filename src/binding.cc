#include <napi.h>
#include <fstream>
#include "md5.h"

Napi::Value Md5Hash(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 1) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    if (!info[0].IsString()) {
        Napi::TypeError::New(env, "md5Hash expects a string").ThrowAsJavaScriptException();
        return env.Null();
    }

    std::string path = info[0].As<Napi::String>();

    std::ifstream inBigArrayFile;
    inBigArrayFile.open(path, std::ios::binary | std::ios::in);

    inBigArrayFile.seekg(0, std::ios::end);
    size_t fileLength = inBigArrayFile.tellg();
    inBigArrayFile.seekg(0, std::ios::beg);

    char* inFileData = new char[fileLength];
    inBigArrayFile.read(inFileData, fileLength);

    MD5* hashComputer = new MD5();

    hashComputer->update(inFileData, fileLength);

    hashComputer->finalize();

    std::string hash = hashComputer->hexdigest();

    delete[] inFileData;

    return Napi::String::New(env, hash);
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
    exports.Set(Napi::String::New(env, "md5Hash"), Napi::Function::New(env, Md5Hash));
    return exports;
}

NODE_API_MODULE(md5Hash, Init)
