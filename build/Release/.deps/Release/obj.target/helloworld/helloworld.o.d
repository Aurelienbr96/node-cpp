cmd_Release/obj.target/helloworld/helloworld.o := c++ -o Release/obj.target/helloworld/helloworld.o ../helloworld.cc '-DNODE_GYP_MODULE_NAME=helloworld' '-DUSING_UV_SHARED=1' '-DUSING_V8_SHARED=1' '-DV8_DEPRECATION_WARNINGS=1' '-D_GLIBCXX_USE_CXX11_ABI=1' '-D_DARWIN_USE_64_BIT_INODE=1' '-D_LARGEFILE_SOURCE' '-D_FILE_OFFSET_BITS=64' '-DNAPI_VERSION=6' '-DBUILDING_NODE_EXTENSION' -I/tmp/.gyp/21.7.0/include/node -I/tmp/.gyp/21.7.0/src -I/tmp/.gyp/21.7.0/deps/openssl/config -I/tmp/.gyp/21.7.0/deps/openssl/openssl/include -I/tmp/.gyp/21.7.0/deps/uv/include -I/tmp/.gyp/21.7.0/deps/zlib -I/tmp/.gyp/21.7.0/deps/v8/include  -O3 -gdwarf-2 -flto -mmacosx-version-min=11.0 -arch arm64 -Wall -Wendif-labels -W -Wno-unused-parameter -std=gnu++17 -stdlib=libc++ -fno-rtti -fno-strict-aliasing -MMD -MF ./Release/.deps/Release/obj.target/helloworld/helloworld.o.d.raw   -c
Release/obj.target/helloworld/helloworld.o: ../helloworld.cc \
  /tmp/.gyp/21.7.0/include/node/node_api.h \
  /tmp/.gyp/21.7.0/include/node/js_native_api.h \
  /tmp/.gyp/21.7.0/include/node/js_native_api_types.h \
  /tmp/.gyp/21.7.0/include/node/node_api_types.h
../helloworld.cc:
/tmp/.gyp/21.7.0/include/node/node_api.h:
/tmp/.gyp/21.7.0/include/node/js_native_api.h:
/tmp/.gyp/21.7.0/include/node/js_native_api_types.h:
/tmp/.gyp/21.7.0/include/node/node_api_types.h:
