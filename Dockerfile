FROM ubuntu:22.04 AS base_image

RUN apt update && apt install -y \
    git \
    cmake \
    make \
    gcc \
    g++ \
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
    jq \
    docker.io \
    wget \
    curl \
    iputils-ping \
    ncat \
    postgresql-client \
    xvfb  && rm -rf /var/lib/apt/lists/*

# extra stuff
RUN apt update && apt install -y \
    libenet-dev \
    jq \
    docker.io \
    curl \
    iputils-ping \
    xvfb \
    postgresql-client && rm -rf /var/lib/apt/lists/*

COPY godot-gdscript-toolkit /godot-gdscript-toolkit

RUN python -m pip install --upgrade pip
RUN cd godot-gdscript-toolkit && python -m pip install .
RUN python -m pip install scons pyenet ipython jsonschema jinja2 pytest tavern cmakelint
RUN git config --global --add safe.directory "*"

FROM base_image AS cxx_base_image
