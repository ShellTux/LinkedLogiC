/*******************************************************************************
 * Project               _     _       _            _ _                 _ _____
 *                      | |   (_)     | |          | | |               (_)  __ \
 *                      | |    _ _ __ | | _____  __| | |     ___   __ _ _| /  \/
 *                      | |   | | '_ \| |/ / _ \/ _` | |    / _ \ / _` | | |
 *                      | |___| | | | |   <  __/ (_| | |___| (_) | (_| | | \__/\
 *                      \_____/_|_| |_|_|\_\___|\__,_\_____/\___/ \__, |_|\____/
 *                                                                 __/ |
 *                                                                |___/
 *
 *
 * Author: Luís Góis
 *
 * This software is licensed as described in the file LICENSE, which
 * you should have received as part of this distribution.
 *
 * You may opt to use, copy, modify, merge, publish, distribute and/or sell
 * copies of the Software, and permit persons to whom the Software is
 * furnished to do so, under the terms of the LICENSE file.
 *
 * This software is distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY
 * KIND, either express or implied.
 *
 ******************************************************************************/

#include "LinkedList.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

LinkedList createLinkedList(const size_t dataSize)
{
	LinkedList list = {0};
	list.dataSize   = dataSize;

	return list;
}

void insertLinkedList(LinkedList *list, const void *const data)
{
	Node *lastNode = NULL;

	for (lastNode = list->head; lastNode != NULL && lastNode->next != NULL;
	     lastNode = lastNode->next) {}

	lastNode = (lastNode == NULL)
	               ? (list->head = malloc(sizeof(*list->head)))
	               : (lastNode->next = malloc(sizeof(Node)));
	list->size++;

	lastNode->data = memcpy(malloc(list->dataSize), data, list->dataSize);
}

void forEachLinkedList(const LinkedList list,
                       void (*forEach)(const size_t index,
                                              const void *const data))
{
	if (forEach == NULL) {
		return;
	}

	size_t i = 0;
	for (Node *node = list.head; node != NULL; node = node->next, ++i) {
		forEach(i, node->data);
	}
}

void printLinkedList(FILE *file, const LinkedList list)
{
	fprintf(file, LINKED_LIST_PRINT_FORMAT "\n", list.size, list.dataSize);
}
