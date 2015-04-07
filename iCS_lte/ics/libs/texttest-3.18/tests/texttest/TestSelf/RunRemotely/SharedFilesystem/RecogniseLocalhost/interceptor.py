
import socket

def gethostname():
    return "my_host_name.my_domain.com"

socket.gethostname = gethostname
