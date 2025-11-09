# Satellite System Simulation Project

The purpose of the project is to demonstrate my ability to learn and implement new information toward upgrading my career. Although satellites are complicated, my focus is to keep the project basic by stripping complicated systems that might normally be found in a standard satellite. GenAI will be used to develop a learning guide, research foundational concepts, and develop code. Although GenAI will produce some of the code, my goal is to understand the code before adding it to the project, which means I will control what code will be added to the project.

## TODO
+ Pick a category of service [SPP Category of Service](https://ccsds.org/Pubs/133x0b2e2.pdf#page=19)

## Project Notes
The simluated satellite downlink will use Binary Phase-Shift Keying (PSK) to make it simple. Use UDP to handle the downlink communication from a satellite.


## How does a Satellite Work?

The payload is the equipment to carry out the mission. The bus includes all systems needed to operate the satellite and support the payload.

+ [Satellite Basics](https://youtu.be/ror4P1UAv_g?si=6pMloxfmEMRQFEEL)
+ [How to Build a Satellite](https://youtu.be/5voQfQOTem8?si=vh1suHiahTLVbZ2Z)

## References

+ [CCSDS: Overview of Space Link Protocols, Green Book](https://ccsds.org/Pubs/130x0g1s.pdf)
+ [CCSDS: Space Packet Protocol, Blue Book](https://ccsds.org/Pubs/133x0b2e2.pdf)
    - [Protocol Specification](https://ccsds.org/Pubs/133x0b2e2.pdf#page=31)
    - [Packet Primary Header](https://ccsds.org/Pubs/133x0b2e2.pdf#page=32)
    - [Packet Data Field (and Secondary Header)](https://ccsds.org/Pubs/133x0b2e2.pdf#page=36)
+ [Computer Networks, Tanenbaum](https://csc-knu.github.io/sys-prog/books/Andrew%20S.%20Tanenbaum%20-%20Computer%20Networks.pdf): terminology and background regarding computer networks
+ [Sockets](https://pubs.opengroup.org/onlinepubs/009696599/basedefs/sys/socket.h.html)