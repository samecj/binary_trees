#include "binary_trees.h"

/**
 * create_node - Creates a new levelorder_queue_t node.
 * @node: The binary tree node for the new node to contain.
 * Return: A pointer to the new node, or NULL on failure.
 */
levelorder_queue_t *create_node(binary_tree_t *node)
{
	levelorder_queue_t *new_node = malloc(sizeof(levelorder_queue_t));

	if (new_node == NULL)
		return (NULL);

	new_node->node = node;
	new_node->next = NULL;

	return (new_node);
}

/**
 * free_queue - Frees a levelorder_queue_t queue.
 * @head: A pointer to the head of the queue.
 */
void free_queue(levelorder_queue_t *head)
{
	levelorder_queue_t *current = head;

	while (current != NULL)
	{

		levelorder_queue_t *temp = current;

		current = current->next;
		free(temp);
	}
}

/**
 * push - Pushes a node to the back of a levelorder_queue_t queue.
 * @node: The binary tree node to push.
 * @head: A pointer to the head of the queue.
 * @tail: A double pointer to the tail of the queue.
 * Description: Exits with a status code of 1 on malloc failure.
 */
void push(binary_tree_t *node, levelorder_queue_t **head,
		levelorder_queue_t **tail)
{
	levelorder_queue_t *new_node = create_node(node);

	if (new_node == NULL)
	{
		free_queue(*head);
		exit(1);
	}

	if (*head == NULL)
		*head = new_node;
	else
		(*tail)->next = new_node;

	*tail = new_node;
}

/**
 * pop - Pops the head of a levelorder_queue_t queue.
 * @head: A double pointer to the head of the queue.
 */
void pop(levelorder_queue_t **head)
{
	if (*head == NULL)
		return;

	levelorder_queue_t *temp = *head;
	*head = (*head)->next;
	free(temp);
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: A pointer to the root node of the tree to check.
 * Return: 1 if the tree is complete, 0 otherwise.
 * Description: Exits with a status code of 1 on malloc failure.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	levelorder_queue_t *head = NULL, *tail = NULL;
	unsigned char flag = 0;

	push((binary_tree_t *)tree, &head, &tail);

	while (head != NULL)
	{
		binary_tree_t *current = head->node;

		if (current->left != NULL)
		{
			if (flag)
			{
				free_queue(head);
				return (0);
			}
			push(current->left, &head, &tail);
		}
		else
			flag = 1;

		if (current->right != NULL)
		{
			if (flag)
			{
				free_queue(head);
				return (0);
			}
			push(current->right, &head, &tail);
		}
		else
			flag = 1;

		pop(&head);
	}
	return (1);
}
