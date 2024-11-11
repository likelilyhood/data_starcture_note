# 数据结构笔记
## 基本数据结构
### 线性表，栈和队列
#### 线性表
'''
事实上，线性表的ADT结构代表，就是常见的数组，对于这样的数据结构，这里有以下元素较为重要，构成了描述的基础元素，首先  
length长度 head表头 tail表尾 sorted list有序表 unsorted list 无序表
如果使用一个C++的抽象结构来描述这样的数据结构，其中的一些操作和对应的逻辑

            clerar()这样的函数，作用来清空整个表，可以直接循环给整个List赋值为零，完成操作
            insert(&pos,item) 在已知位置插入一个新元素
            append(&pos,item) 在表尾添加一个新的元素
            remove(&pos,item) 在该位置进行抹除原有元素
            movetostart(&pos) 从当前位置移动到最初位置
            movetoend(&pos) 从当前位置移动到队尾
            prev(&pos,item) 指针移动到上一位
            next(&pos,item) 指针移动到下一位
            length(&pos,**argv) 通过指针遍历，实现寻找到List的长度并返回
            currpos(&pos,item)  返回对应当前位置以及对应值
            movetopos(&pos) 将该位置改为当前位置
            getvalue(&pos,item) 输出当前位置对应的值

通过上述函数的构成，我们基本完成了对线性表的操作基础，无所谓更加复杂的操作，我们只需要通过组合上述基础操作，就可以实现，换言之，这样的基础操作相当于线性代数的基或者解空间


‘’‘
##### 顺序表和链式表
在顺序表中我们需要补充的要素在于maxsize 也就是最大数据数，因为顺序表是基于数组构建的，对于insert函数这里，我们会发现，我们的操作复杂度是稳定n/2的，对于arraybased是避无可避的问题，在其次，删除也是同理，因为我们需要后续元素向前递补。

在链式表中，我们采用指针构建这种数据结构，或者说采用结点式构建法，比如说以单链表为例，每个结点内只包含对应的数值和指向下一位连接的结点。链式表分为两类，其中之一为对于整个函数已有明确赋值，另外对应的就是为一整个空域

对于一个链表的实现关键在于如何设计表示栅栏或者是选择器的位置选择，对于一般的操作而言都会选择让curr指向当前元素的上一个元素

相对的，在LList中，insert和remove只需要进行一次常数级别的操作即可，即修改后一位和前一位的指向连接就可以了，当然在链表为空或者操作位置在最后一位的时候会存在无法寻找得到后一位的情况，我们可以通过添加特殊表头结点来解决这个问题

 空间的管理与释放   在面对周期性对链表空间的删减时，我们可以编写一个空间函数，将它删除的空间结点储存在另外一个区域中，需要调用时直接安排，这样可以有效提高空间利用率，减少甚至避免系统层次的直接new一片空间，

两种方法的选择与取舍  在可以预估数据规模的情况下，顺序表的空间开销更小，反之亦然

还有在元素的储存存在的选择，面对小数量级以及重复率较低的情况下，采取直接储存元素本身是个不错的选择，然而面对大数量级以及高复杂度的数据，我们一般倾向于直接运用指针进行描述，这样的好处就在于节省空间的同时可以进行更为方便的操作

双链表，这种结构相比单链表多出了相对的尾结点，并且多出了前驱结点，可能在代码长度上有所加强，但是在使用和调试时更为便利，

### 栈和队列
栈是一种限制在一端进行插入或者删除操作的ADT，虽然在结构上受到了限制，但是在效率和可操作性上也获得大大的提升，这是一些基本的术语 栈的可访问元素我们称之为top栈顶元素，将元素入栈我们称之为push，删除我们称之为pop
#### 顺序栈和链式栈
一切基于数组构成的数据结构都会有这样的限制，即是大小的决定，也就是maxsize的存在。而顺序栈的存在就是对顺序表的一个简化，唯一需要明确的就是，我们确定使用数组那一端来表示栈顶，选择第0位或者第n位，会在时间复杂度上存在一个n的区别

同样的链式栈也是对链式表的简化，将对应top的数据类型转换为了指针，同时设置一个临时变量*temp这样就可以实现pop和对应的push操作

优劣比较 对于操作而言都是常数级存在，没有太大区别，然而在存储中，顺序栈可能存在着浪费空间的现象，而链式栈又存在着结构性开销，也就是元素和指针分别占用了空间

如果面对多个栈且空间有限的时候，我们可以选择在同一个数组中两面开栈，但是一定要注意数据集大小，避免数据重复混杂的出现。
### 顺序队列
对于实现顺序队列，我们不能只是单纯的提取和改变线性表的特征，对于数组的输入位置无论enqueue还是dequeue这两个操作的平均时间复杂度o(n-1),存在着更好的优化方法，也就是说我们可以允许数组内部进行移动
然而存在这一些问题，在我们删去（rear）一些元素过后，该元素留下的空间未被占用，而我们继续将元素插入在队尾，会形成一个虚假的空间溢出，然而我们将这个队列创新性的引入一个环，形成一个法老之蛇，这样的话可以有效解决这样的问题
完成队列空间的有效利于。在具体实现中并不是简单的更改rear和front的定义，在面对队列所处于的各种不一样的情况中，单纯的调整无济于事，为了解决这个问题，我们需要判断队列的情况，对于一个队列显然有两种方法来判断队列中各元素的状态
首先当然是固定front，那么rear的值会代表着n-1种状态（同样的固定rear是相同的情况）但是无法判断空或者是溢出的这两种情况，其次，第二种方法直接新建一个计数器，用于记录队列元素中的个数，亦或使用一个bool变量
来指示队列是否为空。
#### 链式队列
链式队列就是简单对链表做了修改，front&rear就是指向队首元素和队尾元素的指针，在具体实现中我们会将front&rear指向同一个初始位置。

### 字典
对于字典这样的ADT而言，我们想要它实现的功能是通过关键字段的搜索来实现数据的快速检索，故而我们需要实现在数据库中的查询，存储和删除记录的功能。

为了实现检索功能，我们提出关键字的概念抑或是ID，对这个特征我们要求他可比，目的是为了有效区别不同字段的关键字，并且构建出关键字和对应内容的全序关系

一个最为基础的还是通过寻找到关键码值相对应的内容，并且希望能够适合任意类型的字典，一种想法是要求我们所有的关键值满足泛化的要求，并且可以满足比较的要求，例如在Java中著名的Comparable结构。另一种方法是实现一个类，兼容较多的类，但是同为遗憾的是
因为关键码的类型过多，难以全部编写出来。

## 二叉树
#### 定义和部分特性
 一棵二叉树（binary tree）由有限的节点（node）来构成，此集合或为空，或者由一个根节点和两个不交叉的二叉树组成，这两颗二叉树分别称为这个根节点的左子树和右子树（其中不相交是指没有公共节点）。这两颗二叉树的对应节点称为
 此二叉树的子节点，从一个节点到他的两个节点相连，这个节点称为父节点。

 如果从n1节点可以到nk节点，那么称存在从n2到nk的路径，这条路的长度就是k-1.其中n1是nk的祖先，nk是n1的子孙。
 
 对于一个树而言，它的深度就是根节点到最深的叶节点的距离，树的高度就是最大深度+1，
 
 没有非空子树的节点我们称之为叶节点，至少有一个非空子树的节点称之为分支节点。

 满二叉树：每一个节点，是一个分支节点，并恰好有两个分支节点，或者是叶节点。

 完全二叉树：从根节点开始每一层从左到右填充，一棵高度为d的完全二叉树除了d-1层外，每一层都是满的。底层叶节点集中在左边的若干位置上。
####  满二叉树定理
定理：非空满二叉树的叶节点数等于其分支节点数加1.

定理：一棵非空二叉树空子树的数目等于其节点数加一。

在分析二叉树的空间代价时，知晓空子树的数目是很有用的。

二叉树的ADT类型

类似于链表的一个链的集合，树就是由一系列的节点构成。

### 遍历二叉树
按照一定顺序访问二叉树的节点，称为遍历（traversal）.对每个节点都进行一定顺序访问并将其列出，类似地，也可以先访问节点的子节点，然后再访问该节点。例如，需要释放树中所有节点占用的空间，在删除节点前应该先删除该节点的子节点
然后再删除节点本身。故而这种访问方法称为后序遍历。
中序遍历：先访问左子节点（包括整棵子树），然后访问该节点，最后访问右节点(包括整颗子树)。

### 二叉树的实现
#### 使用指针实现二叉树
根据定义，每个节点都会有对应的两个子节点，，不论是否为空，那么最为简单的作法，就是选择使用指针，来指向对应的区域
下面是一段具体实现的代码框架
~~~cpp
template<typename Key ,typename E>
class BSTNode : pubilc BinNode<E>
{
private :
 Key k;         //节点对应的索引
 E it;          //节点对应的价值
 BSTNode *lc;   //指向左节点的pointer
 BSTNode *rc;   //指向右节点的pointer

pubilc :
BSTNode(){ lc = rc = NULL}  //对指针进行初始化赋值为空 
BSTNode(Key K,E e ,BSTNode * l=NULL, BSTNode * r=NULL)
{k =K;it =e;lc =l;rc=r;}
~BSTNode(){};
//为键值和价值进行读取和复制
E& element(){return it;}
void setElment(const E&e) {it=e;}
Key &key (){return k;}
void setKey (const Key& K){ k=K;}
//为子节点进行赋值和读取
inline BSTNode* left() const {return lc;}
void setLeft (BSTNde<E>* b){lc = (BSTNode*)b;}
inline BSTNode* reight() const{ return rc;}
void setRight (BSTNode<E>* b){rc =(BSTNode*)b;}
//判断是否为根节点还是子叶
bool isLeaf(){return (lc==NULL)&&(rc==NULL);}
};
~~~

在利用指针实现的二叉树中，叶节点和分支节点是否选用相同的类定义十分重要，使用相同的类可以简化实现，不可避免地带来空间的浪费，因而我们可能会选择分支节点存储某个操作符，在叶节点存储大量的数据或者不同的变量名，同时对于叶节点的进一步优化在于优化掉无用的指向字节点的空指针。

##### 二叉检索树(binary search tree)
在利用二叉搜索中我们找到一个元素的平均时间已经来到logn的时间复杂度，但是在我们需要删改的时候，我们会因为高昂的时间代价而却步，而二叉检索树天降伟人，通过利用树的优良结构同时减少了时间复杂度

我们可以看一下这个定义  对于BST的任意一个节点，设置其值为K，则该节点左子树中任意一个节点的值都小于K；它的右子树中任意值都会大于K的值
 针对这个子树，我们可以明显发现他的特点在于利用中序输出，就会得到由小到大排序的节点。
 下面是搜索思路的描述

从根节点开始，在BST中检索K值，如果根节点存储的值为K，检索结束。否则检索树的下一层。而实现二叉检索树的效率就在于左子树始终比右子树大，我们寻找的K值总能在左右找到位置，重复上述操作，直到找到K.
或者在遇到了一个叶节点就停下来。
~~~cpp
//Binary Search implementation for the Dictionary ADT 
template <typename Key ,typename E>* root ;
class BST : public Dictionary<Key,E>{
  private :
    BSTNode<Key ,E>* root ;
    int nodecount;//记录二叉搜索树的节点数量
    //Private "helper functions "
    void clearhelp(BSTNode<Key,E>*);
    BSTNode<Key,E>* inserthelp(BSTNode<Key,E>*,const Key&, const E&);
    BSTNode<Key,E>* deletemin(BSTNode<Key,E>* );
    BSTNode<Key,E>* getmin(BSTNode<Key,E>* );
    BSTNode<Key,E>* removehelp(BSTNode<Key,E>* ,const Key&);
    E findhelp(BSTNode<Key,E>*,const Key&)const;
    void printhelp(BSTNode <KEy,E>*,int )const;
  public :
    BST(){ root= NULL;nodecount=0;}
    ~BST() {clearhelp(root);}  
    void clear(){
        clearhelp(root);root =NULL;nodecount=0;
    }
    /*插入一个节点到树中
    同时对树的节点K进行更新*/
    void insert(const Key&k,const E&e){
        root = inserthelp(root,key,e);
        nodecount++;

    }
    /*从树中移除一个节点
    并且同时删去它对应的键值*/
    E remove(const Key&k){
    E temp = findhelper(root ,k );//首先找到它
    if(temp != NULL){
        root= removehelp(root ,k );
        nodecount--;
            }
        return temp;
    }
    E removeAny(){
        //Delete min valve
        if( temp !=NULL){
            E temp =root -> element();
            root = removehelp(root,root->key());
            nodecount--;
            renturn temp;
        }
        else return NULL;
    }//在树中删去对应的节点以及并且返回此树是否为空。 ‘
    E find(const Key&k) const{ return findhelp(root ,k);}
    int size () {return nodecount;}
     
    void print () const {   
        if ( root== NULL)cout<<"BST is empty.\n ";
        else printhelp(root,0);
    }
        }
~~~
下面是部分私有函数的实现
```cpp
E BST<Key,E>::findhelp (BSTNode<Key, E>* root , const Key &k)const {
    if (root ==NULL)return NULL;    //Empty
    if(k < root->key())return findhelp(root ->left(),k);    //check left child 
    else if (K>root ->key())return findhelp(root ->right (),k); //check right child
    else return root->element();    //find it 当找到目标节点后，节点的记录信息会随着递归调用依次向上返回
}
// 插入函数 为了实现这个函数首先需要进行寻找到该节点应该存在的地方 
//这意味着将会来到一个叶节点或者一个没有子节点的分支节点，将这个节点设置为插入节点的父节点 并且一般不考虑值相等的情况
inserthelp(BSTNode<Key,E>*root ,const Key& k,const E&it ){
    if (root ==NULL )return new BSTNode <Key,E >(k,it NULL,NULL);
    if (k< root ->key())root->setLeft(inserthelp(root->left(),k,it));
    else root->setRight(inserthelp(root->right(),k,it));
    return root ;   // return tree with inserted one
}
deletemin(BSTNode<Key, E>* rt){//为了找到值最小的点，只需要一直向左走，直到找到最左侧的叶节点
    if (rt->left()==NULL) return rt->right();
    else {
        rt->setleft(deletemin(rt->left()));
        return rt;
    }
}
getmin (BSTNode <Key, E>* rt){//找到对应的最小值
    if (rt->left()==NULL)return rt;
    else return getmin(rt->left());
}
/*将一个非最小节点从BST中删除，首先需要找到该节点，如果这个节点是叶节点，直接将他的父节点修改为NULL
如果对应节点拥有一个子节点，将他的父节点指向他的节点重新指向这个子节点，如果拥有两个节点，问题就出现了，如何将两个子树接上去，
简单的方法是直接接上去一个，但是要将另外一个挨个接上去，这种方法思路简单但是对应的工程量巨大
有一个较好的解决方法是 在父节点的右子树中找到一个近似的子叶中的最小者来代替，这样就可以保持BST的结构完整功能没有太多改变 */
removehelp(BSTNode <Key,E>* rt, const Key&k ){
    if(rt==NULL)return NULL ;
    else if (k < rt->key())
        rt->setRight(removehelp(rt->right(),k));
    else {// found it
        BSTNode<Key ,E>* temp=rt;
        if (rt ->left()==NULL){ //Only a right child 
            rt= rt->right();
            delete temp;
        }
        else if (rt->right()==NULL){// Only a left child 
             rt =rt->left();
             delete temp;
        }
        else {// both child not empty 
        BSTNode <Key, E>* temp = getmin (rt->right ());
        rt->setElement(temp->element());
        rt->setKey(temp->key());
        rt->setRight(deletemin(rt->right()));
        delete temp;

        }
    }
    return rt;
}
void BST<Key,E>::clearhelp(BSTNode<Key, E>* root ){
    if (root ==NULL )return ;
    clearhelp(root->left());
    clearhelp(root->right());
    delete root;
}//清除所有树及其结构
void BST<Key, E>::printhelp(BSTNode<Key, E>*root , int level)const{
    if(root ==NULL) ruturn;
    printhelp(root->left(),level++);    //打印左树
    for( int i=0; i<level;i++)cout<<" ";//记录左子树层数
    cout<<root->key()<<"\n";//输出对应的值
    printhelp(root->right(),level++);//转向右树
}
```

##### 堆（Heap）
堆由两条定义来决定，第一，堆是一个完全二叉树，通常使用数组实现；其次，堆是局部有序的
下面是两种常见的堆：

1.最大堆（max heap）：任意一个节点存储的值都大于或等于其任意一个子节点存储的值。所以根节点会存储着最大值

2.最小堆（min heap）:任意一个节点存储的值都小于或等于其任意一个子节点存储的值。所以根节点会存储着最小值

无论是最小堆还是最大堆，任何一个节点与其兄弟节点之间并没有必然联系，也就是说，只有这个结点是另一个节点的父子节点时才可以确定两者之间的关系。
尽管在大部分情况下堆的实现一般采用数组，但是从逻辑上讲，堆本身是一种严谨的树结构
这是一个最大堆的生成示例
```cpp
//Heap class
template <typename E,typename Comp>class heap {
    private:
        E* Heap;        //Pointer to this array
        int maxsize;    //maxmiun of this heap
        int n;          //number of elements now in the heap

        //Helper function to put element in its correct place
        void siftdown(int pos){
            while (! isLeaf(pos)){//Stop if pos is a leaf
                int j =leftchild (pos);
                int rc =rightchild(pos);
                if (rc<n)&&Comp::prior (Heap[rc],Heap[j])
                    j=rc;       //Set j to greater child's value
                if (Comp::prior (Heap[j],Heap[rc]))return ;//Done
                swap(Heap, pos ,j);
                pos =j;         //Move down 
            }
    }
    pubilc:
        heap(E* h, int num ,int max)    //Comstructor
            {  Heap = h; n =num ; maxsize = max; buildHeap();}
        int size()  const{return n;} 
        bool isLeaf(int pos) const{return (pos>=n/2)&&(pos<n);}//True if pos is a leaf
        int leftchild (int pos )const{return 2*pos+1;}//return leftchild's posistion
        int rightchild (int pos )const{return 2*pos+2;}//return rightchild's posistion
        int parent (int pos)const{return (pos-1)/2;}    //return parent's posistion
        void buildHeap(){for(int i=n/2-1;i>=0;i--)siftdown(i);}//Heapify the content of the heap
        //Insert "it " into the heap
        void insert(const E &it){
            Assert(n< maxsize, "Heap is full");
            int curr =n++;
            Heap[curr]=it ; //start at the end
            //now shift up until curr's parent > curr
            while ((curr!=0)&&(Comp::prior(Heap[curr],Heap(=[parent(curr)])))){
                swap(Heap, curr ,parent(curr));
                curr=parent(curr);
            }
        }
        //remove root 
        E removefirst(){
            Assert(n >0,"Heap is empty");
            swap(Heap,0,--n);   //Swap first with last value
            if( n!=0)siftdown(0);   //siftdown new root val
            return Heap[n]; //return value 
        }
        E remove(int pos){
            Assert((pos>=0)&&(pos <n),"Bad posistion");
            if ( pos==(n-1))n--;
            else{
                swap(Heap,pos,--n); //swap with last value
                while((pos!=0)&&Comp::prior(Heap[pos],Heap[parent(pos)])){
                    swap(Heap, pos ,parent(pos));   //push up large key
                    pos =parent(pos);
                }
                if (n!=0)siftdown(pos);//push down small key
            }
            return Heap[n];
        }
};
```
在类Maxheap中对基于数组的实现进行了两项调整，   
首先，堆的节点根据其在堆中的逻辑位置指示，而不是使用指针指向。
如何解释这句话呢？对于堆这样的数据结构而言，它是完全二叉树，这就意味着，他所有的叶节点都位于最底层，故而在总数为N的一个数组中，后N/2范围内是叶节点，并且按照从左到右的书写方式，按照层来填充数组，排布规则类似于杨辉三角   

其次，指向所用数组的指针作为构造函数的参数，为堆的使用提供了极大便利。

成员函数Heapsize用来反映堆的实时大小，leftchild,rightchild,parent用来反应对应元素的位置（或者说是数组的下标
如何建立一个堆，可以借鉴BST的构建方法，一个一个插入，但是这种算法花费的时间太长，我们基于归纳法提出了一个较优的构建方法：假设左右两个子树都已经是堆了，情况一 R（当作root）值大于等于左右节点的值,此时构建完毕；情况二，小于任一值，此时将R的值和两个子节点中值较大的更换位置，这样得到新堆，直至返回情况一，否则一直保持递归，这样下来所有的复杂度就保持在O（n）的数量级上，远远优于传统的nlogn 复杂度


