FROM conanio/gcc9
COPY . /code
USER root
RUN mkdir /build
WORKDIR /build
RUN conan install /code --build missing -s compiler.libcxx=libstdc++11
RUN cmake /code -DCMAKE_BUILD_TYPE=Release -G "Unix Makefiles" 
RUN make all

