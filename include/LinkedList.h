#ifndef LINKED_LIST_H
#define LINKED_LIST_H

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

#include <stddef.h>
#include <stdio.h>

typedef struct Node {
	void *data;
	struct Node *next;
} Node;

typedef struct {
	size_t size;
	size_t dataSize;
	Node *head;
} LinkedList;

#define LINKED_LIST_PRINT_FORMAT \
	"LinkedList: {\n"        \
	"  size: %zu\n"          \
	"  dataSize: %zu\n"      \
	"}"

LinkedList createLinkedList(const size_t dataSize);
void insertLinkedList(LinkedList *list, const void *const data);
void removeLinkedList(LinkedList *list, const size_t index);
void printLinkedList(FILE *file, const LinkedList list);
void forEachLinkedList(const LinkedList list,
                       void (*forEach)(const size_t index,
                                              const void *const data));

#endif // !LINKED_LIST_H
