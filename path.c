#include "shell.h"


/**
 * add_node_end - adds a new node at the end of a list_t list
 * @head: pointer to pointer to our linked list
 * @str: pointer to string in previous first node
 * Return: address of the new element/node
 */

list_path *add_node_end(list_path **head, char *str)
{
	list_path *tmp = NULL;
	list_path *new = NULL;

	new = calloc((sizeof(list_path)), 1);

	if (!new || !str)
	{
		return (NULL);
	}

	new->dir = str;

	new->p = '\0';
	if (!*head)
	{
		*head = new;
	}
	else
	{
		tmp = *head;

		while (tmp->p)
		{

			tmp = tmp->p;
		}

		tmp->p = new;
	}

	return (*head);
}

/**
 * linkpath - creates a linked list for path directories
 * @path: string of path value
 * Return: pointer to the created linked list
 */
list_path *linkpath(char *path)
{
	list_path *head = '\0'; 
	char *token = NULL;
	char *cpath = strdup(path); 

	token = strtok(cpath, ":"); 
	while (token)
	{
		head = add_node_end(&head, token); 
		token = strtok(NULL, ":");
	}
	return (head);
}

/**
 * _which - finds the pathname of a filename
 * @filename: name of file or command
 * @head: head of linked list of path directories
 * Return: pathname of filename or NULL if no match
 */
char *_which(char *filename, list_path *head)
{
	struct stat st;
	char *string = NULL;

	list_path *tmp = head; 

	while (tmp) 
	{

		string = concat_all(tmp->dir, "/", filename); 
		if (stat(string, &st) == 0)
		{
			return (string);
		}
		free(string);
		tmp = tmp->p;
	}

	return (NULL);
}

/**
 * free_list -  function that frees a linked list.
 * @head: the head of the linked lint
 * Return: nothing
 */
void free_list(list_path *head)
{
	list_path *actual;

	if (!head)
		return;

	while (head->p)
	{
		actual = head->p;
		free(head);
		head = actual;
	}
	free(head);
}
