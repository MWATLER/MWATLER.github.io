pkill -SIGINT msgPump
pkill -SIGINT msgClient
sleep 2
pkill -9 msgPump
pkill -9 msgClient
