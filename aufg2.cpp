
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/* define the class intList {{{
 **************************/
class intList
{
	/* privat part {{{ */
	static int const N = 10;
	
	/* define the structure */
	struct intElem {
		int info;
		intElem *pred, *succ;
	};
	
	/* declare the element array and the array for the memory management */
	intElem elements[N];
	bool memory[N];

	// }}}

public:
	/* define the constructor -- intList () {{{ */
	intList ()
	{
	int i;
	for(i=0;i<N;i++)
		{
			memory[i] = 0;
		};
	};
	// }}}
	
	/* method to check whether memory is free -- request() {{{
	 * *********************************************************/
	intElem* request ()
		{
			int i;
			for(i=0;i<N;i++)
			{
				if ( this->memory[i] = 0 ) return &(this->elements[i]);
			};
			return NULL;
		};
		//}}}

	/* method to free memory in our list -- free() {{{
	 * *************************************************/
	void free (intElem* el)
	{
		int i;
		for(i=0;i<N;i++)
		{
			if( &(this->elements[i]) == el)
			{
				this->memory[i] = 0;
				break;
			}
		};
	}
	//}}}
	
	/* method to insert an element sorted  -- inssorted() {{{
	 * ******************************************************/
	void inssorted (int value)
	{
		/* check whether the list is empty
		 * if true , insert the value at the first elements
		 * TODO: insert element or value only, clean up! */
		int i,j;
		intElem temp,newelement;
		newelement.info = value;	// create an new empty element
		bool isempty = true;
		/* check, whether the list is empty */
		for(i=0;i<N;i++)
		{
			if( memory[i] == 1 )
				isempty = false;
		};
		/* then insert the value at the first element */
		if( isempty == true )
		{
			this->elements[0].info = value;
			memory[0] = 1; // mark space
		}
		else
		{
			/* Insert sorted and move all other elements */
			for(i=0;i<N;i++) 	// first loop to check where the element has to be inserted
			{
			 	if( newelement.info < this->elements[i].info)
				{
					for(j=i;j<N-1 && this->memory[j] != 0;i++)			// no buffer overflow --> last element is cutted
						{
							temp = this->elements[i+1];					// save the following element
							this->elements[i+1] = this->elements[i];	// shift the current element
							this->elements[i] = newelement;				// insert value
							newelement = temp;							// make the saved element the new value
						};
				};
			};
		};


	}	
	//}}}
	
	/* method to print the list and the memory map -- print() {{{
	 * *********************************************************/
	void print ()
		{
			int i;
			for(i=0;i<N;i++)
			{
				if ( memory[i] != 0 )
					printf("%4d ",elements[i].info);
				else
					printf("%4s ","N");
			};
			printf("\n"); 

			for(i=0;i<N;i++)
			{
				printf("%4d ",memory[i]); 
			};
			printf("\n"); 
		};
		//}}}

	/* getter
	 * ******/
	int getlength() { return this->N; };
};
// }}}

int main ()
{

	/* create an instance of intList */
	intList bsplist;



}

	
