import socket

ESP32_IP = "192.168.4.1"
ESP32_PORT = 1234

def main():
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        print(f"Connecting to ESP32 at {ESP32_IP}:{ESP32_PORT}")
        s.connect((ESP32_IP, ESP32_PORT))
        print("Connected!")

        try: 
            while True:
                data = s.recv(1024)
                if not data : 
                    break
                print(data.decode().strip())
                
        except KeyboardInterrupt:
            print("\nDisconnected by user\n")
        except Exception as e:
            print(f"Error : {e}")

if __name__ == "__main__":
    main()
