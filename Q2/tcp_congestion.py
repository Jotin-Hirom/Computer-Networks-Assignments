from mininet.net import Mininet
from mininet.node import Controller
from mininet.link import TCLink
from mininet.cli import CLI

def run():
    net = Mininet(controller=Controller, link=TCLink)

    net.addController('c0')

    h1 = net.addHost('h1')
    h2 = net.addHost('h2')

    # 10 Mbps link with default delay
    net.addLink(h1, h2, bw=10)

    net.start()

    print("Run server on h1 and client on h2")
    CLI(net)

    net.stop()

if __name__ == '__main__':
    run()

