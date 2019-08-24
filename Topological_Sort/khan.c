#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 50

typedef struct adj_list adj_list;
typedef struct graph graph;
typedef struct node node;
typedef struct stack stack;
typedef struct queue queue;

struct adj_list 
{
	int item;
	adj_list *next;
};
struct graph 
{
	adj_list *vertices[MAX_SIZE];
	short indegree[MAX_SIZE];
	short removed[MAX_SIZE];
};
struct node
{
	int item;
	node* next;
};
struct stack
{
	node* top;
};
struct queue
{
	node *head;	
};


graph* create_graph()
{
	graph *graph1 = (graph*)malloc(sizeof(graph));
	int i;
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



//STACK

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
int is_empty_q(queue *queue)
{
	return (queue->head == NULL);
}

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

void print_q(queue *queue) //função que imprime fila
{
    if (!is_empty_q(queue)) // se a fila não estiver vazia a função segue
    {
        node *current = queue->head; //cria um ponteiro pra nó, para  poder se navegar na fila
        while (current != NULL)      //enquanto o ponteiro não chega no fim da fila
        {
            printf("%d ", current->item); //printa o item do ponteiro
            current = current->next;                        //atualiza o ponteiro
        }
        printf("\n");
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


int KHAN(graph *graph, queue *queue, struct queue *sec_q, int source, int size)
{
	
	int u;
	
	for(int i =0;i < size;i++)
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
		enqueue(sec_q, u);

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

	return (size == size_q(sec_q));
}

int main(int argc, char const *argv[])
{
	graph *graph1 = create_graph();
	queue *queue1 = create_queue();
	struct queue *sec_q = create_queue();

	add_edge(graph1, 0, 2);
	add_edge(graph1, 0, 1);
	//add_edge(graph1, 1, 0);
	add_edge(graph1, 2, 4);
	add_edge(graph1, 2, 3);
	add_edge(graph1, 3, 4);

	if(!KHAN(graph1, queue1, sec_q, 0, 6))
	{
		printf("This graph is not a DAG!\n");
	}
	else
	{
		print_q(sec_q);
	}
	//top_sort(stack1, graph1, 8);	
	//print_stack(stack1->top);
	return 0;
}
