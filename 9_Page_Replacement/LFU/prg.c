#include <stdio.h>
#include <stdlib.h>

#define MAX_PAGES 10

struct page {
  int number;
  int count;
};

struct page *pages;
int page_faults;

void init_pages() {
  pages = malloc(sizeof(struct page) * MAX_PAGES);
  for (int i = 0; i < MAX_PAGES; i++) {
    pages[i].number = -1;
    pages[i].count = 0;
  }
}

void reference_page(int page_number) {
  // Check if the page is already in memory.
  for (int i = 0; i < MAX_PAGES; i++) {
    if (pages[i].number == page_number) {
      // The page is already in memory, so increment its count.
      pages[i].count++;
      return;
    }
  }

  // The page is not in memory, so we need to find a page to replace it with.
  // We will use the LFU algorithm to find the least frequently used page.
  int min_count = 99999;
  int min_index = -1;
  for (int i = 0; i < MAX_PAGES; i++) {
    if (pages[i].number == -1) {
      // This page is free, so we can use it to replace the missing page.
      min_index = i;
      break;
    } else if (pages[i].count < min_count) {
      min_count = pages[i].count;
      min_index = i;
    }
  }

  // If we couldn't find a free page, we need to replace a page that is already in memory.
  if (min_index == -1) {
    min_index = rand() % MAX_PAGES;
  }

  // Replace the page with the missing page.
  pages[min_index].number = page_number;
  pages[min_index].count = 1;
  page_faults++;
}

int main() {
  init_pages();

  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    int page_number;
    scanf("%d", &page_number);
    reference_page(page_number);
  }

  printf("Number of page faults: %d\n", page_faults);

  return 0;
}
