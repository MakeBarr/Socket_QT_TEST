# Socket_QT_TEST

Testing Project

// SREVER PREPARE

gcc server.c -o server
./server &

netstat -anp --tcp | grep server

telnet localhost 5001

// QT CLIENT START

tripplaner
