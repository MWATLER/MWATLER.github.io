#!/bin/bash
#Test race conditions
./race1&
sleep 1
./race2&
sleep 1
./fcntl&
