import socket
from threading import Thread


# Multithreaded Python server
class ClientThread(Thread):

    def __init__(self, ip, port):
        Thread.__init__(self)
        self.ip = ip
        self.port = port
        
    def run(self):
        while True:
            try:
                MESSAGE = input("Input response:")
                conn.send(MESSAGE.encode("utf8"))  # echo
                data = conn.recv(2048)
                if len(data) != 0:
                    print("Response:")
                    print(data)
            except Exception as e:
                print(e)
                break

TCP_IP = "192.168.43.214"
TCP_PORT = 80
BUFFER_SIZE = 20

tcpServer = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
tcpServer.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
tcpServer.bind((TCP_IP, TCP_PORT))
threads = []

while True:
    tcpServer.listen(4)
    (conn, (ip, port)) = tcpServer.accept()
    newthread = ClientThread(ip, port)
    newthread.start()
    threads.append(newthread)
for t in threads:
    t.join()
