pkill -2 server
pkill -2 client1
pkill -2 client2
pkill -2 client3
sleep 3
echo "Make sure they've stopped"
pkill -9 server
pkill -9 client1
pkill -9 client2
pkill -9 client3
