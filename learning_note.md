# 数据结构笔记
## 基本数据结构
### 线性表，栈和队列
#### 线性表
事实上，线性表的ADT结构代表，就是常见的数组，对于这样的数据结构，这里有以下元素较为重要，构成了描述的基础元素，首先  
length长度 head表头 tail表尾 sorted list有序表 unsorted list 无序表
如果使用一个C++的抽象结构来描述这样的数据结构，其中的一些操作和对应的逻辑
~~~
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
~~~
通过上述函数的构成，我们基本完成了对线性表的操作基础，无所谓更加复杂的操作，我们只需要通过组合上述基础操作，就可以实现，换言之，这样的基础操作相当于线性代数的基或者解空间


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
#### 顺序队列
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
                std::swap(Heap, pos ,j);
                pos =j;         //Move down 
            }
    }
    public:
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
            while ((curr!=0)&&(Comp::prior(Heap[curr],Heap([parent(curr)])))){
                std::swap(Heap, curr ,parent(curr));
                curr=parent(curr);
            }
        }
        //remove root 
        E removefirst(){
            Assert(n >0,"Heap is empty");
            std::swap(Heap,0,--n);   //Swap first with last value
            if( n!=0)siftdown(0);   //siftdown new root val
            return Heap[n]; //return value 
        }
        E remove(int pos){
            Assert((pos>=0)&&(pos <n),"Bad posistion");
            if ( pos==(n-1))n--;
            else{
                std::swap(Heap,pos,--n); //swap with last value
                while((pos!=0)&&Comp::prior(Heap[pos],Heap[parent(pos)])){
                    std::swap(Heap, pos ,parent(pos));   //push up large key
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

#####   Huffman 编码树
哈夫曼编码的引入 在程序应用中，时间和空间总是两两相对，为了提高运行效率，我们不免会牺牲空间作为代价，同样的，牺牲时间处理来节省空间在早期游戏优化中尤为常见，在这样的两方徘徊着中，有没有一种较为折中的方法，可以兼得其利
答案就是哈夫曼编码，哈夫曼编码的理念就是根据出现和使用频率来规划时间和空间的分配，对于出现频次高的，我们给予更多的空间，便于减少他的响应时间，同样的。对于较低频次的，我们对他的空间采取压缩处理，节省空间，因为调用而产生的而外时间开销
在较低的频率下是一个可以接受的代价。
###### 实现哈夫曼编码树
哈夫曼编码树的每一个叶节点对应着一个字母，叶节点的权重就是他出现的频率大小，目的在于按照最小外部路径建立一一棵树，一个叶节点的加权深度定义为 权重mutiple深度。具有最小外部路径权重的二叉树就是，对于给定的叶节点集合，具有加权路径长度最小之和的二叉树。
具体描述来看就是权重大的叶节点的深度小，因为他相对总路径的花费最小，那么可以预见，权重相对较小的叶节点就会被推向更深的节点

建立一个n个节点的哈夫曼树： 首先，创建n个初始的Haffman树。每个树只包含唯一的叶节点，将这个n棵树按照频率大小顺序排成一列，接着拿走前两个最小的树（顺序是按照从小到大排布的）将这两个树标记为一个分支节点的子树，那么这个新节点的权重或者频率就是两个子树的和，再次重新排序，重新迭代，直至剩余最后的一个，结束流程
（生动描述一下 ，就是不停的合并两个最小的，生成一个较大的，然后继续排序，再次重新合并，直至剩下一个

事实上哈夫曼编码树的建立就是贪心算法的具体体现

下面是Haffman节点 的具体代码实现
```cpp
//Huffman tree node ADT
template <typename E>class Huffnode {
    public:
    virtual ~huffNode (){}//基础编译
    virtual int weight()=0;//返回对应的频率或者是权重
    virtual bool isLef ()=0;//决定是否是分段
};
template <typename E>//叶节点的实现
class LeafNode : public HuffNode<E>{
    private :
        E it;
        int wgt ;
    public:
        LeafNode(const E&val , int freq){it = val ;wgt = freq;}
        int weight (){return wgt ;}
        E val (){return it ;}
        bool isLeaf(){return true ;}
        
        }
template <typename E>// 分支节点的实现
class IntlNode : public HuffNode <E>{
    private :
        HuffNode <E>*lc;//左子节点
        HuffNode <E>*rc;//右子节点
        int wgt ;   //新节点的权重
    public:
        IntlNode (HuffNode<E>* l,HuffNode <E>*r){wgt = l->weight()+r->weight();lc=l;rc=r;}
        int weight (){return wgt;}
        bool isLeaf(){return false ;}
        HuffNode <E>* left() const {return lc;}
        void setleft (HuffNode<E>* b)
        {lc = (HuffNode <E>* )b;}

        HuffNode <E>* right() const {return rc;}
        void setRight (HuffNode<E>* b)
        {rc = (HuffNode <E>* )b;}
        
} ;
```
下面这部分代码是哈夫曼树的类说明
```cpp
template <typename E>* Root ;
    public :
        HuffTree(E& val, int freq)//叶节点的设置
        { Root = new LeafNode<E>(val ,freq);}
        HuffTree(HuffTree<E>* l,HuffTree<E>* r)
        { Root = new IntlNode <E>(l->root (),r->root());}
        ~HuffTree() {}
        HuffNode <E>* root (){return Root;}
        int weight (){
            return Root->weight();
        }
```
Huffman树构造函数的实现
```cpp
template <typename E>HuffTree<E>*
buildHuffTree (HuffTree<e>** TreeArray ,int count ){
    heap <HuffTree<E>*,minTreeComp>* forest =
        new heap<HuffTree<E>*,minTreeComp>(TreeArray,count ,count );
    HuffTree<char>* temp1,temp2,temp3=NULL;
    while(forest->size()>1){
        temp1= forest->removefirst();//将前两个子树推出当前子树集
        temp2= forest->removefirst();
        temp3= new HuffTree<E>(temp1,temp2);
        forest->insert(temp3);//将新树还回原有集
        delete temp1;
        delete temp2;//删掉之前剔除掉的子树
    }
    return temp3;
}
```

##### 哈夫曼编码和使用方法
从根节点开始，分别将“0”和“1”标在树的每条边上，0代表左子节点，1代表右子节点，根据频率大小来决定对应的编号从而进一步决定排布编码。

当我们在哈夫曼树中进行搜索时，可以按照字符串的0/1代码值来在树中经历相应的路径，最后找到对应的值

## 树
#### 定义和部分术语
一棵树T是一个或者一个以上的节点组成的有限集，其中一个节点R我们称之为根节点，如果这集合T-R非空，那么剩下的节点将被划分为N个不相交的集合，其中每个节点都是树，他们的根节点都是R的子节点，这些子集被称为子树，
子树从左到右排序，将最左端的子树称为最左子树。节点的出度（out degree）定义为该节点的子节点的数目.森林定义为一个或多个树的集合。
除了根节点没有父节点之外，书的每一个节点都正好有一个父节点，不难得出，节点为n的树必然有n-1条边，因为除了根节点之外，每一个点都必然会和父节点有一个连线

#### 树节点的ADT
给出一棵树，我们对其必须实现的操作要有直接访问根节点的方法和访问一个节点的子节点的函数，不同于二叉树的至多两个节点，树的出度并不限制是二，因此我们需要找到一种可以寻找未知数量节点的方法

第一种方法就是提供一个函数，他的一个参数指定了子节点的序号数，在这个函数和另外一个给定返回子节点数目的函数结合之下，就可以支持对任一节点的直接访问，以及对应的所有子节点的处理。按照我们要求来看，这样的方法可能选用数组实现以便支持对随机节点的访问，但是事实上选用更多的是链表

第二种方法是提供对节点的最左子节点以及下一个（右相邻）兄弟节点的访问，利用这两个函数，可以像链表一样，遍历该节点的各个子节点
这是第二种方法代码示例
```cpp
//树节点的实现
template <tyoename E>class GTNode {
    public :
    E value();  //返回节点的值
    bool isLeaf();  //当是叶子时，返回true 
    GTNode* parent();       //返回父节点
    GTNode* leftmostchild();//返回最左节点
    GTNode* rightSilibing();//返回下一个右兄弟
    void setvalue(E&);      //初始化对应的值
    void insertFirst(GTNode<E>* );//插入第一个子节点
    void insertNext(GTNode<E>* );//在下一个子节点位置插入
    void removeFirst();//删除第一个
    void removeNext();//删除下一个子节点
    };
    
    template <typename E>class GenTree {
        public :
            void clear();
            GTNode<E>* root();
            void newroot(E&, GTNode<E>*,GTNode<E>*);
            void print();

    }
```

### 树的遍历
与二叉树中前序 中序 后序遍历较为相似，但是由于树的节点的数量的不确定性，我们一般不用中序遍历了
#### 父指针表示法
实现树最简单的方法就是对每一个节点只保留一个指针域，指向其父节点，在寻找最左节点或者最右兄弟节点中缺少这基本信息，然而这种方法可以完美解答“给出两个独立的节点，此两节点是否在同一棵树中？”，为了解决这样的问题我们只需要追溯的他们各自的根节点，一旦重合，就可以很好的解答这个问题
这样的方式一般称为FIND

父指针表示法常常用来维护一些不相交的子集构成的集合中，对于这样的结构，我们非常希望提供以下两种操作  

判断这两个节点是否在同一个树中

归并（UNION）两个集合

所以我们对这种方法命名为并查法，在这种算法中用一棵树来表示一个集合，书中的每个节点（根节点除外）都有且仅有一个父节点，这样我们可以用相同的空间来存贮每个节点，节点一般使用数组来进行，并且同时存储对应的值.
每个元素还与不同的不相交树中的节点对应，因此还可以将节点的父指针存储到数组中，那些有子节点的节点，同时也是子树的根节点的，存储了指向子树的指针，这样通过了一个数组表述了一个树结构
在归并的过程中我们需要坚守保持秩最小的原则，或者说保持着最小深度

归并法并不限制各个子节点指向父节点的数目，为了使等价对的处理尽可能高效，故而每个子节点到根节点的距离应该尽可能的小，理想情况下，每棵树的节点都应指向根节点，但实际操作中，我们可能付出过多的额外开销，以至于得不偿失，那么相应的优化方法也应运而生，就是加权合并规则，在合并两个节点数目不同的树时，我们会选择将节点数较小的哪一个指向节点较多的树的根节点，这样就可以将树的整体深度限制在logn左右，对于节点较少的
树中，所有的节点深度增加1 ，而合并后树中最深节点的深度最多只能增加1

加权合并规则有利于树深度的减少，然而路劲压缩是一种更好的方法，在查找一个节点为X的根节点时，我们可以直接将从X到R的路径上每一个节点都指向R，这样的操作使得FIND操作时间成本无限接近于常数

### 树的实现 

在树的表示法中，有多种方式来存储和表示树结构，特别是在有限内存的情况下。

#### 1. 子节点表示法

**普通子节点表示法**：
在这种表示法中，树的每个节点都有指向其所有子节点的指针。对于非叶子节点，这些指针通常存储在一个列表或数组中。这种方法在表示多叉树时非常直观，但可能会浪费空间，因为不是所有节点都有相同数量的子节点。

**示例**：
```plaintext
    A
   /|\
  B C D
 / \
E   F
```
在这个例子中，节点A有三个子节点（B、C、D），节点B有两个子节点（E、F）。

#### 2. 左子节点和右兄弟表示法

**左子节点和右兄弟表示法**：
这种表示法利用了每个节点的两个指针，一个指向其左子节点，另一个指向其右兄弟节点。在这种表示法中，第一个子节点被视为左子节点，紧接着的子节点被视为右兄弟节点。

**示例**：
```plaintext
    A
   /|\
  B C D
 / \
E   F
```
在这种表示法中，A的左子节点是B，B的右兄弟是C，C的右兄弟是D。B的左子节点是E，E的右兄弟是F。

#### 3. 动态节点表示法

**动态节点表示法**：
这种表示法是普通子节点表示法的一种优化，它使用动态数据结构（如链表）来存储子节点，从而节省空间。每个节点只存储指向其子节点链表的头指针，链表中的每个元素都是一个节点，代表一个子节点。

#### 4. 动态左子节点和右兄弟表示法

**动态左子节点和右兄弟表示法**：
这种表示法结合了左子节点和右兄弟表示法与动态节点表示法的优点。每个节点仍然有两个指针，一个指向其左子节点，另一个指向其右兄弟节点。但是，左子节点不再是单一的节点，而是一个链表的头节点，这个链表包含了所有的子节点。

**示例**：
```plaintext
    A
   /|\
  B C D
 / \
E   F
```
在这种表示法中，A的左子节点是B（链表的头节点），B的右兄弟是C（链表的第二个节点），C的右兄弟是D（链表的第三个节点）。B的左子节点是E（链表的头节点），E的右兄弟是F（链表的第二个节点）。

### 树的顺序表示法
树的顺序表示法是一种利用数组来存储树结构的方法，尤其适用于完全二叉树或满二叉树。在这种表示法中，树中的节点被存储在一个一维数组中，数组的索引与树中节点的层次和顺序相对应。这种表示法假设即使树不是完全二叉树，也将其视为一个完全二叉树来处理，即在数组中留出必要的空位以保持完全二叉树的结构。

#### 完全二叉树的顺序表示法

在完全二叉树的顺序表示法中，对于数组中索引为`i`的节点（索引从0开始）：
- 其左子节点的索引是`2*i + 1`。
- 其右子节点的索引是`2*i + 2`。
- 其父节点的索引是`(i-1)/2`（对于根节点，其索引为0，没有父节点）。

**示例**：
```plaintext
    A
   / \
  B   C
 / \
D   E
```
在这个例子中，节点A、B、C、D、E的数组索引分别为0、1、2、3、4。节点B的左子节点是D（索引3），右子节点是E（索引4）。

### 一般树的顺序表示法

对于一般的二叉树，顺序表示法需要额外的信息来表示树的结构，因为非完全二叉树在数组中会有空隙。一种方法是使用一个额外的数组来存储每个节点的索引，这样就可以知道每个节点的父节点、左子节点和右子节点的位置。

**示例**：
```plaintext
    A
   /
  B
 /
D
```
在这个例子中，我们可以使用一个数组来存储节点的索引，其中每个节点存储其左子节点和右子节点的索引：
- 节点A在索引0，左子节点索引为1，右子节点索引为-1（表示没有右子节点）。
- 节点B在索引1，左子节点索引为2，右子节点索引为-1。
- 节点D在索引2，左子节点索引为-1，右子节点索引为-1。

数组表示为：`[A, B, D]`，附加索引数组表示为：`[-1, 2, -1]`（A的左子节点是B，B的左子节点是D，其余为-1）。

### 顺序表示法的优缺点

**优点**：
- **空间效率**：对于完全二叉树，顺序表示法非常节省空间，因为它不需要额外的指针。
- **快速访问**：可以通过简单的算术运算快速访问任何节点的子节点。

**缺点**：
- **限制性**：只适用于完全二叉树，对于非完全二叉树，需要额外的数据结构来表示。
- **动态调整**：当树的大小变化时，可能需要重新调整数组的大小，这在某些情况下可能是低效的。

顺序表示法在实际应用中，如堆（特别是二叉堆）的实现中非常常见，因为它可以快速地进行父节点和子节点之间的转换。这种表示法的简洁性和效率使其成为处理完全二叉树的理想选择。
## 图


### 图的基本术语

**顶点（Vertex）/节点（Node）**：图的基本构成元素，可以代表任何实体，比如网络中的一个节点或社交网络中的一个用户。

**图例**：
```plaintext
A --- B
|    |
C --- D
```
在这里，A、B、C和D都是顶点。

**边（Edge）/弧（Arc）**：连接两个顶点的线，表示顶点之间的关系或连接。

**图例**：
```plaintext
A --- B (表示A和B之间有一条边)
```
这条线就是边，表示A和B之间的连接。

**邻接（Adjacent）**：如果两个顶点之间有边相连，则称这两个顶点是邻接的。

**度（Degree）**：一个顶点的边的数量。在无向图中，度是连接到该顶点的所有边的数量；在有向图中，度分为入度和出度。

**图例**：
```plaintext
A --- B
|    |
C --- D
```
在无向图中，A和B的度为2，C和D的度为1。

**路径（Path）**：一系列顶点的序列，其中每对连续的顶点都是邻接的。

**环（Cycle）**：一个特殊的路径，其起点和终点是同一个顶点。

**简单路径（Simple Path）**：路径中不包含重复的顶点。

**连通（Connected）**：如果图中任意两个顶点之间都存在路径，则称图是连通的。

**强连通（Strongly Connected）**：对于有向图，如果任意两个顶点之间都存在有向路径，则称图是强连通的。

**权重（Weight）**：图中边的属性，表示边的成本、长度或权重。

**子图（Subgraph）**：由原图的一部分顶点和边组成的图。

**完全图（Complete Graph）**：图中每对不同的顶点之间都恰好有一条边相连。

**二分图（Bipartite Graph）**：顶点可以被分成两个不相交的集合，使得同一集合内的顶点之间没有边。

#### 图的表示法

**邻接矩阵（Adjacency Matrix）**：一个二维数组，用于表示顶点之间的连接关系。

**图例**：
```plaintext
图：
A --- B
|    |
C --- D

邻接矩阵：
  [[0, 1, 0, 1],
   [1, 0, 1, 0],
   [0, 1, 0, 1],
   [1, 0, 1, 0]]
```
在这个矩阵中，1表示相应的顶点之间有边相连。

**邻接表（Adjacency List）**：一个数组或列表的列表，其中每个列表包含一个顶点的所有邻接顶点。

**图例**：
```plaintext
图：
A --- B
|    |
C --- D

邻接表：
A: [B, C]
B: [A, D]
C: [A, D]
D: [B, C]
```
每个顶点都对应一个列表，包含它的所有邻接顶点。

**边列表（Edge List）**：一个包含所有边的列表，每条边表示为一对顶点（对于无向图）或有序对（对于有向图）。

**图例**：
```plaintext
图：
A --- B
|    |
C --- D

边列表：
[(A, B), (A, C), (B, D), (C, D)]
```
这个列表包含了图中所有的边。

**邻接多重集（Adjacency Multiset）**：类似于邻接表，但每个顶点的邻接列表中可以包含重复的邻接顶点，用于表示多重图。

**边的字典（Dictionary of Edges）**：使用字典来存储边的信息，其中键是顶点对，值是边的属性（如权重）。

**图例**：
```plaintext
图：
A --- B (权重 3)
|         |
C --- D (权重 2)

边的字典：
{
  (A, B): {weight: 3},
  (A, C): {weight: 1},
  (B, D): {weight: 2},
  (C, D): {weight: 1}
}
```
这个字典包含了每条边及其权重。

如果图是稀疏的，邻接表比邻接矩阵更节省空间。反之，如果图是密集的，邻接矩阵可能更高效。
图是一种复杂的数据结构，用于表示对象之间的复杂关系。在计算机科学中，图的实现通常有两种方式：邻接矩阵和邻接表。下面将分别解释这两种实现的原理，并提供C++代码描述和单独的代码解释，最后进行比较。

### 图的实现原理

1. **邻接矩阵**：使用一个二维数组来表示图，其中数组的行和列对应于图中的顶点。如果顶点i和顶点j之间有边，则矩阵中相应的元素被标记为1（或边的权重），否则为0。这种方式可以快速确定两个顶点之间是否存在边，但空间复杂度高，尤其是在稀疏图中。

2. **邻接表**：使用一个数组，其中每个元素是一个链表，用来存储与该顶点相邻的顶点。这种方式在稀疏图中更加节省空间，因为它只存储实际存在的边。

以下是使用邻接矩阵和邻接表实现图的C++代码示例。

**邻接矩阵实现**：

```cpp
template<class T>
class MGraph {
public:
    int vertexNum; // 顶点数量
    int arcNum;   // 边的数量
    T* vertex;    // 顶点数组
    int** arc;    // 邻接矩阵

    MGraph(T a[], int n, int e); // 构造函数
    void DFSTraaverse(int v);   // 深度优先遍历
    void BFSTraverse(int v);   // 广度优先遍历
};
```

**邻接表实现**：

```cpp
struct ArcNode { // 边表节点
    int adjvex; // 邻接点域
    ArcNode* next;
};

struct VertexNode { // 顶点表节点
    int vertex;
    ArcNode* firstedge;
};

template<class T>
class ALGraph {
public:
    VertexNode adjlist[MaxSize]; // 邻接表
    int vertexNum, arcNum;       // 图中顶点数和边数

    ALGraph(T a[], int n, int e); // 构造函数
    void DFSTraaverse(int v);    // 深度优先遍历
    void BFSTraverse(int v);    // 广度优先遍历
};
```



**邻接矩阵**：

- `MGraph`类使用两个数组：`vertex`存储顶点信息，`arc`存储邻接矩阵。
- `DFSTraaverse`和`BFSTraverse`成员函数分别实现了深度优先和广度优先遍历。

**邻接表**：

- `ALGraph`类使用`VertexNode`数组`adjlist`来存储每个顶点的邻接表。
- `ArcNode`结构体表示邻接表中的节点，包含邻接点索引和指向下一个邻接点的指针。
- `DFSTraaverse`和`BFSTraverse`成员函数同样实现了深度优先和广度优先遍历。



  **空间效率**：邻接表在表示稀疏图时更加节省空间，因为它只存储存在的边。而邻接矩阵无论边是否存在都会分配空间。
  **时间效率**：邻接矩阵可以快速判断两个顶点之间是否存在边（O(1)时间复杂度），而邻接表需要遍历邻接链表（O(度数)时间复杂度）。
  **灵活性**：邻接表更容易添加或删除边，而邻接矩阵在图中边的数量变化时可能需要重新分配内存。

在图的遍历中，深度优先搜索（DFS）和广度优先搜索（BFS）是两种基本的算法。下面将提供这两种遍历算法的C++代码实现，并解释它们的功能。

#### 深度优先搜索（DFS）

深度优先搜索（DFS）是一种用于遍历或搜索树或图的算法。它从一个节点开始，尽可能深地搜索树的分支。在图的遍历中，DFS会访问一个节点，然后递归地访问它的所有未访问的邻居。

**DFS的C++代码实现（邻接矩阵）**：

```cpp
template<class T>
void MGraph<T>::DFSTraaverse(int v) {
    bool visited[vertexNum];
    for (int i = 0; i < vertexNum; i++) visited[i] = false;

    DFS(v, visited);
}

template<class T>
void MGraph<T>::DFS(int v, bool visited[]) {
    visited[v] = true;
    cout << vertex[v] << " "; // 访问节点v

    for (int i = 0; i < vertexNum; i++) {
        if (arc[v][i] && !visited[i]) {
            DFS(i, visited); // 递归访问未访问的邻接点
        }
    }
}
```

**DFS的C++代码实现（邻接表）**：

```cpp
template<class T>
void ALGraph<T>::DFSTraaverse(int v) {
    bool visited[vertexNum];
    for (int i = 0; i < vertexNum; i++) visited[i] = false;

    DFS(v, visited);
}

template<class T>
void ALGraph<T>::DFS(int v, bool visited[]) {
    visited[v] = true;
    cout << adjlist[v].vertex << " "; // 访问节点v

    for (ArcNode* p = adjlist[v].firstedge; p; p = p->next) {
        int w = p->adjvex;
        if (!visited[w]) {
            DFS(w, visited); // 递归访问未访问的邻接点
        }
    }
}
```
基于之前的讨论，我们将为邻接表表示的加权图书写的成员函数，包括`setEdge`、`delEdge`、`getMark`、`setMark`、`next`和`weight`。这些函数将帮助我们管理图中的边和顶点的状态。

### 邻接表的类定义和成员函数

```cpp
#include <iostream>
#include <vector>
#include <limits>

struct ArcNode { // 带权重的边表节点
    int adjvex; // 邻接点索引
    int weight; // 边的权重
    ArcNode* next;
    ArcNode(int v = -1, int w = 0, ArcNode* n = nullptr) : adjvex(v), weight(w), next(n) {}
};

struct VertexNode { // 顶点表节点
    int vertex; // 顶点信息
    ArcNode* firstedge; // 指向第一个邻接点
    int mark; // 顶点标记，用于遍历等操作
    VertexNode(int v = -1, ArcNode* n = nullptr, int m = 0) : vertex(v), firstedge(n), mark(m) {}
};

class ALGraph {
private:
    std::vector<VertexNode> adjlist; // 邻接表
    int vertexNum, arcNum; // 图中顶点数和边数

public:
    ALGraph(int n) : vertexNum(n), arcNum(0) {
        adjlist.resize(n);
        for (int i = 0; i < n; ++i) {
            adjlist[i] = VertexNode(i);
        }
    }

    // 添加边
    void setEdge(int u, int v, int w) {
        ArcNode* newNode = new ArcNode(v, w, adjlist[u].firstedge);
        adjlist[u].firstedge = newNode;
        arcNum++;
    }

    // 删除边
    void delEdge(int u, int v) {
        ArcNode* prev = nullptr;
        ArcNode* curr = adjlist[u].firstedge;
        while (curr != nullptr && curr->adjvex != v) {
            prev = curr;
            curr = curr->next;
        }
        if (curr) {
            if (prev) prev->next = curr->next;
            else adjlist[u].firstedge = curr->next;
            delete curr;
            arcNum--;
        }
    }

    // 获取顶点的标记
    int getMark(int v) const {
        return adjlist[v].mark;
    }

    // 设置顶点的标记
    void setMark(int v, int m) {
        adjlist[v].mark = m;
    }

    // 获取下一个邻接点
    ArcNode* next(int v) const {
        return adjlist[v].firstedge;
    }

    // 获取边的权重
    int weight(int v, int u) const {
        for (ArcNode* node = adjlist[v].firstedge; node != nullptr; node = node->next) {
            if (node->adjvex == u) return node->weight;
        }
        return -1; // 表示没有找到边
    }
};
```

1. **setEdge**：此函数用于在图中添加一条从顶点`u`到顶点`v`的边，并带有权重`w`。它创建一个新的`ArcNode`并将其插入到顶点`u`的邻接链表的头部。

2. **delEdge**：此函数用于删除从顶点`u`到顶点`v`的边。它遍历顶点`u`的邻接链表，找到对应的边，然后将其从链表中移除。

3. **getMark**：此函数返回顶点`v`的标记值。

4. **setMark**：此函数设置顶点`v`的标记值为`m`。这通常在图的遍历算法中使用，以标记已访问的顶点。

5. **next**：此函数返回顶点`v`的第一个邻接点的指针，这可以用来开始遍历顶点的邻接链表。

6. **weight**：此函数返回从顶点`v`到顶点`u`的边的权重。如果不存在这样的边，它返回-1。

这些函数提供了对图的基本操作，包括边的添加和删除，以及对顶点的遍历和标记。这些操作是图算法中常见的基本操作，例如深度优先搜索（DFS）和广度优先搜索（BFS）。

#### 广度优先搜索（BFS）

广度优先搜索（BFS）是一种用于遍历或搜索树或图的算法。它从一个节点开始，先访问所有邻接点，然后是邻接点的邻接点，依此类推。

**BFS的C++代码实现（邻接矩阵）**：

```cpp
template<class T>
void MGraph<T>::BFSTraverse(int v) {
    bool visited[vertexNum];
    int queue[vertexNum]; // 使用数组模拟队列
    int front = 0, rear = 0;

    for (int i = 0; i < vertexNum; i++) visited[i] = false;

    visited[v] = true;
    queue[rear++] = v; // 将起始节点入队

    while (front != rear) {
        v = queue[front++]; // 队列出队
        cout << vertex[v] << " "; // 访问节点v

        for (int i = 0; i < vertexNum; i++) {
            if (arc[v][i] && !visited[i]) {
                visited[i] = true;
                queue[rear++] = i; // 邻接点入队
            }
        }
    }
}
```

**BFS的C++代码实现（邻接表）**：

```cpp
template<class T>
void ALGraph<T>::BFSTraverse(int v) {
    bool visited[vertexNum];
    int queue[vertexNum]; // 使用数组模拟队列
    int front = 0, rear = 0;

    for (int i = 0; i < vertexNum; i++) visited[i] = false;

    visited[v] = true;
    queue[rear++] = v; // 将起始节点入队

    while (front != rear) {
        v = queue[front++]; // 队列出队
        cout << adjlist[v].vertex << " "; // 访问节点v

        for (ArcNode* p = adjlist[v].firstedge; p; p = p->next) {
            int w = p->adjvex;
            if (!visited[w]) {
                visited[w] = true;
                queue[rear++] = w; // 邻接点入队
            }
        }
    }
}
```

##### 功能介绍

- **DFS**：这两种DFS实现都使用了一个辅助数组`visited`来记录节点是否被访问过。递归版本直接递归地访问所有未访问的邻接点。
- **BFS**：这两种BFS实现都使用了一个队列来记录待访问的节点。它们从起始节点开始，逐层访问所有邻接点。

 **时间复杂度**：DFS和BFS的时间复杂度都是O(V+E)，其中V是顶点数，E是边数。
 **空间复杂度**：DFS的空间复杂度主要取决于递归栈的深度，最坏情况下为O(V)。BFS的空间复杂度主要取决于队列的大小，最坏情况下也为O(V)。
 **遍历顺序**：DFS会尽可能深地搜索一个分支，而BFS会逐层遍历节点。

这两种遍历算法各有优势，DFS适合于寻找路径或解决谜题，而BFS适合于找到最短路径或层次遍历。
拓扑排序（Topological Sorting）是针对有向无环图（Directed Acyclic Graph，简称DAG）的一种排序算法。它将图中的所有顶点排成一个线性序列，使得对于任何一条有向边\(U \rightarrow V\)，顶点\(U\)都在顶点\(V\)的前面。也就是说，对于每个有向边，其源顶点（tail）在排序结果中都出现在目标顶点（head）之前。

### 拓扑排序

1. **有向无环图**：拓扑排序仅适用于有向无环图，如果图中存在环，则无法进行拓扑排序。
2. **非唯一性**：对于同一个有向无环图，可能存在多个拓扑排序序列。
3. **依赖关系**：在很多实际问题中，拓扑排序可以表示任务之间的依赖关系，例如在任务调度、课程规划等场景。

##### 拓扑排序的算法：

有两种常见的算法用于实现拓扑排序：

1. **基于入度的算法**：
   - 计算每个顶点的入度（即指向该顶点的边的数量）。
   - 将所有入度为0的顶点放入一个队列（或栈）中。
   - 当队列不为空时，执行以下操作：
     - 从队列中移除一个顶点，并将其加入到拓扑排序的结果中。
     - 遍历该顶点的所有邻接点，将每个邻接点的入度减1。如果某个邻接点的入度变为0，则将其加入队列中。
   - 如果所有顶点都被加入到结果中，则得到一个拓扑排序序列；如果队列中没有顶点但图中还有未被加入结果的顶点，则说明图中含有环。

2. **深度优先搜索（DFS）**：
   - 使用DFS遍历图。
   - 在DFS的回溯阶段（即从某个顶点返回到其父顶点时），将顶点加入到拓扑排序的结果中。
   - 需要一个栈来记录访问的顶点顺序，以处理环的检测。


#### 松弛操作的步骤：
1. **考虑一条边**：取一条边\((u, v)\)，其中\(u\)是当前考虑的顶点，\(v\)是它的邻接点。

2. **当前最短路径估计**：假设你已经有一个从源点到顶点\(u\)的最短路径估计，记为\(d[u]\)。

3. **通过\(u\)到达\(v\)的路径**：计算通过顶点\(u\)从源点到顶点\(v\)的路径长度，这个长度是\(d[u] + weight(u, v)\)，其中\(weight(u, v)\)是边\((u, v)\)的权重。

4. **比较路径长度**：将这个新计算的路径长度与之前对\(d[v]\)的估计进行比较。

5. **更新最短路径估计**：
   - 如果通过\(u\)到达\(v\)的路径长度小于当前的\(d[v]\)，则更新\(d[v]\)为这个新的更小的值。这意味着你找到了一条更短的路径到顶点\(v\)。
   - 如果不小于，那么不做任何操作，因为当前的路径已经是最短的。

6. **重复**：对图中的每条边重复执行这个操作。

换言之，松弛操作的直观理解是，你不断地尝试通过已经确定的最短路径顶点来更新其他顶点的最短路径。每次成功的更新都意味着你找到了一条更短的路径到达某个顶点。


在后面提供的Dijkstra算法的代码示例中，松弛操作体现在以下部分：
```cpp
if (dist[u] + weight < dist[v]) {
    dist[v] = dist[u] + weight;
    pq.push({dist[v], v});
}
```

这里，`dist[u] + weight`计算了通过顶点`u`到达顶点`v`的路径长度，如果这个长度小于当前已知的最短路径长度`dist[v]`，则更新`dist[v]`，并把顶点`v`重新加入优先队列中，以便进一步探索从`v`出发的更短路径。这就是一次完整的松弛操作。

下面是一个简化版的Dijkstra算法实现，我们将整个算法封装在一个函数中，并添加详细的注释来解释每一步的逻辑。

```cpp

// Dijkstra算法寻找单源最短路径
vector<int> dijkstra(const vector<vector<pair<int, int>>>& graph, int src) {
    int V = graph.size(); // 图中顶点的数量
    vector<int> dist(V, INT_MAX); // 存储最短距离，初始设为无穷大
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // 小顶堆，存储顶点和对应的距离

    // 初始化源点到自己的距离为0，并将源点加入优先队列
    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second; // 获取当前距离最小的顶点
        pq.pop();

        // 遍历当前顶点的所有邻接点
        for (auto edge : graph[u]) {
            int v = edge.first; // 邻接点
            int weight = edge.second; // 边的权重

            // 执行松弛操作，更新邻接点的距离
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight; // 更新距离
                pq.push({dist[v], v}); // 将更新后的邻接点加入优先队列
            }
        }
    }
    return dist; // 返回从源点到所有顶点的最短距离数组
}
```

#### 代码逻辑解释：

1. **函数定义**：`dijkstra`函数接受一个图的邻接表表示和一个源点`src`作为参数，返回从源点到所有顶点的最短距离数组。

2. **初始化**：定义一个距离数组`dist`，所有值初始化为无穷大，表示从源点到其他顶点的初始距离未知。源点到自己的距离设为0。

3. **优先队列**：使用一个优先队列`pq`来存储顶点和它们到源点的距离，队列中始终保持距离最小的顶点在顶部。

4. **循环处理**：当优先队列不为空时，重复以下步骤：
   - 从队列中取出距离最小的顶点`u`。
   - 遍历顶点`u`的所有邻接点，对于每个邻接点`v`，执行松弛操作，即如果通过`u`到达`v`的距离比当前已知的最短距离更短，则更新`v`的距离，并将`v`重新加入优先队列。

5. **返回结果**：返回包含从源点到所有顶点的最短距离的数组。

### 最小支撑树


最小支撑树（Minimum Spanning Tree，MST）是指在一个连通的无向带权图中，包含所有顶点的子图（即树），其边的总权重最小，且任意两个顶点间都是连通的。换句话说，最小支撑树是连接图中所有顶点的最小代价的树形结构。对于一个有\( n \)个顶点的连通图，其最小支撑树将恰好包含\( n-1 \)条边。

下面是一个最小支撑树的图示：

```
      2
     / \
    1---3
     \ /
      0
```

在这个图中，顶点0、1、2、3构成了一个连通图，其最小支撑树可能是顶点1、2、3和边(1-0)、(1-2)、(1-3)，假设这些边的权重之和是最小的。这个树覆盖了所有顶点，且边的总数是顶点数减一，即\( n-1 \)。
1. **无向带权连通图**：最小支撑树是保证其子图连通的权值最小的树。
2. **支撑树结构**：自然就是\( n-1 \)条边的连通无回路的支撑子图（树的性质）。
最小支撑树可能不唯一，判断最小支撑树是否存在多种的本质是判断是否能替换中间的某些边使得最小支撑树的权重相同。
#### Prim算法
Prim算法是一种贪心算法，用于寻找加权连通图的最小生成树。算法从任意一个顶点开始，逐渐增加新的顶点到树中，直到所有顶点都被包含进来。
1. **初始化**：选择一个起始顶点，将该顶点加入到最小生成树的顶点集合中，并初始化一个数组来记录最小生成树中每个顶点到已选择顶点集合的最小边权重。
2. **选择最小边**：在所有连接最小生成树集合和剩余顶点集合的边中，选择权重最小的边。
3. **更新**：将选择的边和它的邻接点加入到最小生成树中，并更新数组。
4. **重复**：重复步骤2和3，直到所有顶点都被加入到最小生成树中。
```cpp


// 图的类
class Graph {
    int V; // 顶点数
    vector<vector<pair<int, int>>> adj; // 邻接表

public:
    Graph(int V) : V(V), adj(V) {}

    // 添加边
    void addEdge(int u, int v, int w) {
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w)); // 无向图
    }
    // Prim算法
    void primMST() {
        vector<int> key(V, INT_MAX); // 存储顶点到MST的最小权重
        vector<bool> inMST(V, false); // 标记顶点是否已经在MST中
        vector<int> parent(V, -1); // 存储MST的父节点
        // 从第一个顶点开始构建MST
        key[0] = 0;
        parent[0] = -1;
        for (int count = 0; count < V - 1; ++count) {
            // 选择最小权重的顶点
            int u = minKey(key, inMST);
            inMST[u] = true; // 将顶点u加入MST
            // 更新与顶点u相邻的顶点的权重
            for (auto i = adj[u].begin(); i != adj[u].end(); ++i) {
                int v = i->first;
                int weight = i->second;

                // 如果v不在MST中，并且权重小于key[v]，则更新key[v]和parent[v]
                if (!inMST[v] && weight < key[v]) {
                    parent[v] = u;
                    key[v] = weight;
                }
            }
        }

        // 打印MST
        printMST(parent);
    }

    // 找到不在MST中且key值最小的顶点
    int minKey(vector<int>& key, vector<bool>& inMST) {
        int min = INT_MAX, min_index;
        for (int v = 0; v < V; ++v) {
            if (!inMST[v] && key[v] < min) {
                min = key[v], min_index = v;
            }
        }
        return min_index;
    }

    // 打印MST
    void printMST(vector<int>& parent) {
        cout << "Edge \tWeight\n";
        for (int i = 1; i < V; ++i)
            cout << parent[i] << " - " << i << "\t" << adj[i][0].second << "\n";
    }
};
```

#### Kruskal算法
Kruskal算法也是一种贪心算法，用于寻找加权连通图的最小生成树。算法从所有边的集合开始，按照权重从小到大排序，然后迭代地选择最小的边，但要确保加上这条边不会形成环。
1. **排序**：将图中的所有边按照权重从小到大排序。
2. **初始化**：创建一个空的边集合来存储最小生成树的边。
3. **选择边**：从排序后的边集合中，选择最小的边，如果这条边与已选择的边集合不形成环，则将其加入到最小生成树中。
4. **重复**：重复步骤3，直到最小生成树中有\( V-1 \)条边。
```cpp
// 边的结构体
struct Edge {
    int src, dest, weight;
};

// 图的类
class Graph {
    int V; // 顶点数
    vector<Edge> edges; // 边集合

public:
    Graph(int V) : V(V) {}

    // 添加边
    void addEdge(int u, int v, int w) {
        edges.push_back({u, v, w});
    }
    // Kruskal算法
    vector<Edge> kruskalMST() {
        vector<Edge> result; // 存储MST的边
        vector<int> parent(V);
        // 找到每个顶点的父节点
        for (int i = 0; i < V; ++i) {
            parent[i] = i;
        }
        // 按权重排序所有边
        sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b) {
            return a.weight < b.weight;
        });
        for (Edge &e : edges) {
            int x = findParent(e.src, parent);
            int y = findParent(e.dest, parent);

            // 如果这条边不形成环，则加入MST
            if (x != y) {
                result.push_back(e);
                parent[x] = y; // 合并集合
            }
        }

        return result;
    }
    // 查找并合并集合
    int findParent(int i, vector<int> &parent) {
        if (parent[i] != i)
            parent[i] = findParent(parent[i], parent);

        return parent[i];
    }
};

```
这两个算法都是构建最小生成树的有效方法，选择哪个算法取决于图的稠密度。对于稠密图，Prim算法更有效；而对于稀疏图，Kruskal算法更有效。
