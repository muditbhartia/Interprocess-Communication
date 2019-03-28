# Interprocess-Communication

This project is based on studying the number of micro-kernel operating system's inter-process communication mechanisms and improved methods, this project presents mechanism of inter-process communication. It contains programmed codes for interprocess communications using C sockets as well as using FIFO(named pipes).


### INTRODUCTION: 
	
Interprocess communication (IPC) is a set of programming interfaces that allow a programmer to coordinate activities among different program processes that can run concurrently in an operating system. This allows a program to handle many user requests at the same time. Since even a single user request may result in multiple processes running in the operating system on the user's behalf, the processes need to communicate with each other. The IPC interfaces make this possible. Each IPC method has its own advantages and limitations so it is not unusual for a single program to use all of the IPC methods.
Many applications are both clients and servers, as commonly seen in distributed computing. Methods for doing IPC are divided into categories which vary based on software requirements, such as performance and modularity requirements, and system circumstances, such as network bandwidth and latency. 
IPC is very important to the design process for microkernels and nanokernels. Microkernels reduce the number of functionalities provided by the kernel. Those functionalities are then obtained by communicating with servers via IPC, increasing drastically the number of IPC compared to a regular monolithic kernel.
A process can be of two type:

1.	Independent process.
2.	Co-operating process.

An independent process is not affected by the execution of other processes while a co-operating process can be affected by other executing processes. Though one can think that those processes, which are running independently, will execute very efficiently but in practical, there are many situations when co-operative nature can be utilised for increasing computational speed, convenience and modularity. Inter process communication (IPC) is a mechanism which allows processes to communicate each other and synchronize their actions. 


### MODULES:
 

* ### Inter process communication using C sockets

A standard model for distributed applications is the client-server model. A server is a process that is waiting to be contacted by a client process so that the server can do something or the client. A typical scenario is as follows:
The server process is started on some computer system. It initializes itself, then goes to sleep waiting for a client process to contact it requesting some service.
A client process is started, either on the same system or on another system that is connected to the server's system with a network. The client process sends a request across the network to the server requesting a service of some form.
When the server process has finished providing its service to the client, the server goes back to sleep, waiting for the next client request to arrive.

Sockets provide point-to-point, two-way communication between two processes. Sockets are very versatile and are a basic component of interprocess and intersystem communication. A socket is an endpoint of communication to which a name can be bound. It has a type and one or more associated processes.
Sockets exist in communication domains. A socket domain is an abstraction that provides an addressing structure and a set of protocols. Sockets connect only with sockets in the same domain. Twenty three socket domains are identified, of which only the UNIX and Internet domains are normally used Solaris 2.x Sockets can be used to communicate between processes on a single system, like other forms of IPC.

<img width="231" alt="Screenshot 2019-03-28 at 10 40 06 PM" src="https://user-images.githubusercontent.com/45623734/55177954-72926e00-51aa-11e9-9617-2ced41ead8e3.png">


* ###	Inter process communication using FIFO (Named PIPES)

Pipes are used for unidirectional communication of related process only. The main thing you have to note here is the limitation of the data to be passed. The capacity of data to be sent through pipes are limited. As like standard communication the output of one pipe can be given as an input of another pipe. It is not necessary to free them after the process has been finished.
A pipe is a serial communication device (i.e., the data is read in the order in which it was written), which allows a unidirectional communication. The data written to end is read back from the other end.

The pipe is mainly used to communicate between two threads in a single process or between parent and child process. Pipes can only connect the related process. In shell, the symbol | can be used to create a pipe.

The solution to this problem of IPC within unrelated processes is given by means of named pipes. The communication can be done between unrelated processes. 
Moreover, it can be bi-directional as well.
One more difference between pipes and named pipes is that the capacity of data i.e. the amount of data flow through a pipe during execution.

<img width="315" alt="Screenshot 2019-03-28 at 10 40 42 PM" src="https://user-images.githubusercontent.com/45623734/55177987-86d66b00-51aa-11e9-9a85-111c47944cf4.png">

### Code Implementaion for IPC

1. ###	Using Sockets in C

1. Open the Terminal
2. Go to the directory where the code is saved
3. Write the following command in terminal:

```
gcc server.c -pthread

./a.out 1200

```

1. Open the Terminal in the same directory
2. Write the following command in terminal:

```
gcc client.c -pthread

./a.out 1200

```

#### NOTE : The port number must be the same for both the client and server to communicate
#### For Multiple Communication between multiple clients you can open new terminal tabs and run the client code again



2. ###	Using Named Pipes FIFO

1. Open the Terminal
2. Go to the directory where the code is saved
3. Write the following command in terminal:

```
gcc write.c && ./a.out

```

1. Open the Terminal in the same directory
2. Write the following command in terminal:

```
gcc read.c && ./a.out

```
