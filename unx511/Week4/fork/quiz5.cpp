//quiz5.cpp - Quiz 5 source code
//
// 01-Feb-19  M. Watler         Created.

#include <iostream>
#include <unistd.h>

int main() {
        int data=1;

        //Assume getpid() here returns a pid of 1000
        std::cout << std::endl << "pid:" << getpid() << " Hello World" << std::endl;
        pid_t childPid = fork();
        //Question 1: Where does the child process start executing? From here, or from main()?
    

        //Question 2: What is childPid for the parent?
    
    
        //Question 3: What is childPid for the child?


        if(childPid==0) {
                for(int i=0; i<3; ++i) {
                        sleep(1);
			std::cout << "pid: " << getpid() << " i:" << i << " data:" << data << std::endl;
                }
                //Question 4: What do you expect to see on the screen for each iteration of i?
	



        }
        else {
		std::cout << "Parent: pid:" << getpid() << " childPid:" << childPid << std::endl;
                for(int i=0; i<3; ++i) {
                        sleep(1);
                        ++data;
			std::cout << "pid: " << getpid() << " i:" << i << " data:" << data << std::endl;
                }
                //Question 5: What do you expect to see on the screen for each iteration of i?
	


        }

	std::cout << "pid:" << getpid() << " Finished!" << std::endl;
        //Question 6: What do you expect to see on the screen here?



        return 0;
}
