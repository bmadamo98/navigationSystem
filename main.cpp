#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;
using std::toupper;

#include "utility.h"


// Function to read in user input

int nextCommand(int *s, int *t, int *f) 
{
	char c;
	while (1){
		scanf("%c", &c);
		if(c >= 97){
			c = c - 32;
		}
		
		if ( c == ' ' || c == '\t' || c == '\n'){
			continue;
		}
		if(c == 'S' || c == 'R' || c == 'W'){
			break;
		}
		if(c == 'P'){
			scanf("%d", s); scanf("%d", t); scanf("%d", f);
			break;
		}
		printf("Invalid Command \n");
	}
	return c;
}

// main function 
//
int main(){
	// variables for parser 
	char c;
	int s, t, f, x, y, a, b, z;
	int edge = 0;
	struct Graph* graph;
	ifstream inFILE;

	while(1){
		c = nextCommand(&s, &t, &f);
	switch (c){
		case 'S':
		{
			// end program
			printf("COMMAND: %c.\n", c);
			exit(0);
		}
		case 'R':
		{
			printf("COMMAND: %c.\n", c);
			
			// reading in file input 
			inFILE.open("Ginput.txt");
			if(inFILE.fail()){
				cout << "Error.";
				break;
			}
			
			inFILE >> x;
			inFILE >> y;
			edge = y;
			
			graph = makeGraph(x);
			
			int num = 0;
			while(!inFILE.eof()){
				inFILE >> a; inFILE >> b; inFILE >> z;
				if( a > graph->V || b > graph->V){
					cout << "Error! One of the vertices on this edge is out of bounds!";
				}else{
					addEdge(graph,a,b,z);
					num++;
				}
			}
		if(num != edge) {
		cout << "Warning! Number of edges is different from what was specified at the start of the file.";
		}
	
		break;	
		}
		case 'W':
		{
			printf("COMMAND: %c.\n",c);
			printGraph(graph);
			cout << endl;	
		break;
		}
		case 'P':
		{
			printf("COMMAND: %c %d %d %d.\n",c, s, t, f);
                        if(s > graph->V || t > graph->V){
                                cout << "Warning! One or more of the nodes is out of bounds!";
                                break;
                        }
			dijkstra(graph, s, t, f);
			cout <<	endl;
		break;
		}
		default: break;
		}
	}
return 0;
}
