#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

struct trump
{
  int order;
  char shape[3];
  int number;  /* data */
};
void make_card(struct trump m_card[]);
void display_card(struct trump m_card[]);
void shuffle_card(struct trump m_card[]);

int main(void)
{
  struct trump card[52];
  make_card(card);
  shuffle_card(card);
  display_card(card);
  return 0;
}

void make_card(struct trump m_card[])
{
  int i,j,k=0;
  char shape[4][3]={"♠","♥","◆","♣"};
  for(i=0;i<4;i++)
    for(j=1;j<=13;j++)
      {
        m_card[k].order=k+1;
        strcpy(m_card[k].shape,shape[i]);
        m_card[k].number=j;
        k++;
      }
}
void shuffle_card(struct trump m_card[])
{
  int i,j;
  struct trump temp;
  srand(time(NULL));
  for(i=0;i<1000;i++)
    {
      j=rand()%52;
      temp=m_card[0];
      m_card[0]=m_card[j];
      m_card[j]=temp;
    }
}
void display_card(struct trump m_card[])
{
  int i;
  for(i=0;i<52;i++)
    {
      printf("%2d:%s%2d ",m_card[i].order,m_card[i].shape,m_card[i].number);
      if((i+1)%13==0) printf("\n");
    }
}