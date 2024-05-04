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

void printElement(const size_t index, const void *const data)
{
	int element = *(int *) data;
	if (index > 0) {
		printf(" -> ");
	}

	printf("%d", element);
}

int main(void)
{
	LinkedList list = createLinkedList(sizeof(int));

	for (int i = 0; i < 10; ++i) {
		int random = rand() % 10;
		insertLinkedList(&list, &random);
	}

	forEachLinkedList(list, printElement);
	printf("\n");

	printLinkedList(stdout, list);

	return 0;
}
