FROM ubuntu:22.04 AS cxx_boilerplate_base_image


RUN apt-get update && apt-get install --no-install-recommends -y \
    git \
    cmake \
    make \
    gcc \
    g++ \
    clang \
    build-essential \
    clang-format \
    clang-tidy \
    autoconf \
    libtool \
    screen \
    python3 \
    python3-pip \
    python-is-python3 \
    libluajit-5.1-dev \
    libmysqlclient-dev \
    libboost-system-dev \
    libboost-iostreams-dev \
    libboost-filesystem-dev \
    libpugixml-dev \
    libcrypto++-dev \
    libfmt-dev \
    libboost-date-time-dev \
    libboost-all-dev \
    jq \
    docker.io \
    wget \
    curl \
    iputils-ping \
    ncat \
    postgresql-client \
    xvfb \
    gdb \
    valgrind \
    file \
    shellcheck && rm -rf /var/lib/apt/lists/*

RUN apt-get update && apt-get install --no-install-recommends -y \
    linux-tools-common \
    linux-tools-generic \
    linux-tools-6.5.0-14-generic \
    && rm -rf /var/lib/apt/lists/*

RUN wget -O /bin/hadolint https://github.com/hadolint/hadolint/releases/download/v1.16.3/hadolint-Linux-x86_64

RUN chmod +x /bin/hadolint

RUN pip install --no-cache-dir --upgrade pip "psycopg[binary,pool]" pgcli hadolintw

FROM cxx_boilerplate_base_image AS build

WORKDIR /src 
COPY . /src
RUN git clean -xfd
RUN cmake -S /src -B /build -D CMAKE_BUILD_TYPE=Debug && cmake --build /build

FROM cxx_boilerplate_base_image AS cxx_boilerplate_image
COPY --from=build /src /src
COPY --from=build /build /build
