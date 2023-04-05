#include "LinkedList.h"


//1. 템플릿 클래스로 확장해야함
template<class T>
//2. Stack형식으로 Delete 함수 재정의해야함
//주의: first, current_size는 class의 멤버 변수이기 때문에 this 포인터를 사용하여 가져와야함

//LinkedList class를 상속받음
class Stack: public LinkedList<T>{
	public:
		bool Delete (T &element){
			if (this->first == 0) //만일 Stack이 비어있는 경우
				return false;

			Node<T>* current = this->first; //current는 첫번째 노드를 가리키는 포인터이다.
			// LinkedList와 달리 Stack은 current가 가리키는 노드를 제거한다.
			this->first = this->first->link; //따라서 first가 다음 노드를 가리키도록 한다.
			element = current->data; //삭제될 데이터를 element에 저장한다.
			delete current; //노드 제거
			this->current_size--; //스택의 크기를 1 감소시킨다.


			return true;
			}
};

