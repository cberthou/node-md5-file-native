# Node MD5 file native

A simple native implementation of a synchronous MD5 hash computation. This is for demonstration purpose only, as it is
not optimized nor uses asynchronous callbacks.

## C++ MD5

The md5 C++ implementation comes from [this article](http://www.zedwood.com/article/cpp-md5-function). 

## Use project

Install deps with
```
yarn
```

Setup node-gyp with
```
yarn configure
```

Build the native module with
```
yarn build
```

Run the tests with
```
yarn test
```
