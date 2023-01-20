#!/bin/bash

### Set initial time of file
LTIME=`stat -c %Z main.cc`

while true
do
   ATIME=`stat -c %Z main.cc`

   if [[ "$ATIME" != "$LTIME" ]]
   then    
       make && ./main && echo " -- done --"
       LTIME=$ATIME
   fi
   sleep 1
done
