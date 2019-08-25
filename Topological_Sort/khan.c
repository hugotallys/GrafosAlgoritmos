#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10000

typedef struct adj_list adj_list;
typedef struct graph graph;
typedef struct node node;
typedef struct queue queue;

//STRUCTS

struct adj_list 
{
	int item;
	adj_list *next;
};
struct graph 
{
	adj_list **vertices;
	short *indegree;
	short *removed;
};
struct node
{
	int item;
	node* next;
};
struct queue
{
	node *head;	
};

//GRAPH

graph* create_graph()
{
	graph *graph1 = (graph*)malloc(sizeof(graph));
	int i;
	graph1->vertices = (adj_list**)malloc(sizeof(adj_list)*MAX_SIZE);
	graph1->indegree = (short*)malloc(sizeof(short)*MAX_SIZE);
	graph1->removed = (short*)malloc(sizeof(short)*MAX_SIZE);
	for (i = 0; i < MAX_SIZE; i++) 
	{
		graph1->vertices[i] = NULL;
		graph1->indegree[i] = 0;
		graph1->removed[i] = 0;
	}
	return graph1;
}
adj_list* create_adj_list(int item)
{
	adj_list *new_adj_list = (adj_list*) malloc(sizeof(adj_list));
	new_adj_list->item = item;
	new_adj_list->next = NULL;
	return new_adj_list;
}
void add_edge(graph *graph, int vertex1, int vertex2)
{
	adj_list *vertex = create_adj_list(vertex2);
	vertex->next = graph->vertices[vertex1];
	graph->vertices[vertex1] = vertex;
	graph->indegree[vertex2]++;
}

//QUEUE

node* create_node (int item)
{
	node* new_node = (node*)malloc(sizeof(node));
	new_node->item = item;
	new_node->next = NULL;
	return new_node; 
}

queue *create_queue()
{
	queue *new_queue = (queue*)malloc(sizeof(queue));
	new_queue->head = NULL;

	return new_queue;
}
int is_empty_q(queue *queue) { return (queue->head == NULL); }

void enqueue(queue *pq, int i)
{
	node *new_node = (node*) malloc(sizeof(node));
	new_node->item = i;
	new_node->next = NULL;

	if(is_empty_q(pq))
	{
		pq->head = new_node;
	}
	else
	{		
		node *current = pq->head;

		while (current->next != NULL)
		{
			current = current->next;
		}

		
		current->next = new_node;
	}
}

int dequeue(queue *pq)
{
	if (is_empty_q(pq))
	{
		printf("Priority Queue underflow");
		return -9999;
	} 
	else 
	{
		node *aux = pq->head;
		pq->head = pq->head->next;
		aux->next = NULL;
		return aux->item;
	}
}

void print_q(queue *queue, FILE *out) 
{
    if (!is_empty_q(queue)) 
    {
        node *current = queue->head;  
        while (current != NULL)      
        {
            fprintf(out, "%d ", current->item); 
            current = current->next;                     
        }
        fprintf(out, "\n");
    }
}


int size_q(queue *queue)
{
	int count = 0;
	node *aux = queue->head;
	while(aux != NULL)
	{
		count++;
		aux = aux->next;
	}

	return count;
}

//ALGORITHM

int KHAN(graph *graph, struct queue *queue, struct queue *second_queue, int source, int size)
{
	
	int u;
	
	for(int i = 0;i < size;i++)
	{
		if(graph->indegree[i] == 0)
		{
			enqueue(queue, i);
		}
	}

	while(!is_empty_q(queue))
	{
		u = dequeue(queue);
		graph->removed[u] = 1;
		enqueue(second_queue, u);

		adj_list *aux = graph->vertices[u];
		
		while(aux != NULL)
		{
			if(!graph->removed[aux->item] && --graph->indegree[aux->item] == 0)
			{
				enqueue(queue, aux->item);
			}
			aux = aux->next;
		}

	}

	return (size == size_q(second_queue));
}

int main(int argc, char const *argv[])
{
	graph *graph1 = create_graph();
	queue *first_queue = create_queue();
	queue *second_queue = create_queue();
	FILE *in, *out;
	int size = 0, vertex1, vertex2;

	//open the input
	in = fopen("in", "r");
	//add edges
	while(!feof(in))
	{
		fscanf(in, "%d %d", &vertex1, &vertex2);
		add_edge(graph1, vertex1, vertex2);
		size++;
	}
	fclose(in);
	//run algorithm
	out = fopen("out", "w");
	if(!KHAN(graph1, first_queue, second_queue, 0, size))
	{
		printf("This graph is not a DAG!\n");
	}
	else
	{
		print_q(second_queue, out);
	}
	//free pointers
	free(graph1);
	free(first_queue);
	free(second_queue);
	fclose(out);
	return 0;
}
