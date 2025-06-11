# set base image
FROM ubuntu:latest

# Install dependencies
RUN apt-get update && apt-get install -y build-essential 
# intall GDB
RUN apt-get install -y gdb

WORKDIR /src 
COPY . .

# Add a command to run on container start
# CMD