## Read input as specified in the question.
## Print output as specified in the question.
import queue
class BinaryTreeNode:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def isSibling(root,p,q):
    if root is None:
        return False
    if root.left is not None and root.right is not None:
        if (root.left.data==p and root.right.data==q):
            return True
        if (root.left.data==q and root.right.data==p):
            return True
        
    ans1=isSibling(root.left,p,q)
    ans2=isSibling(root.right,p,q)
    return ans1 or ans2
def depth(root,data):
    if root is None :
        return -1
    if root.data==data:
        return 0
    leftDepth=depth(root.left,data)
    if leftDepth!=-1:
        return leftDepth+1
    rightDepth=depth(root.right,data)
    if rightDepth!=-1:
        return rightDepth+1
    return -1

def checkCousins(root,p,q):
    if depth(root,p)==depth(root,q) and isSibling(root,p,q)is False:
        return True
    else :
        return False
    #Implement Your Code Here
    pass

def buildLevelTree(levelorder):
    index = 0
    length = len(levelorder)
    if length<=0 or levelorder[0]==-1:
        return None
    root = BinaryTreeNode(levelorder[index])
    index += 1
    q = queue.Queue()
    q.put(root)
    while not q.empty():
        currentNode = q.get()
        leftChild = levelorder[index]
        index += 1
        if leftChild != -1:
            leftNode = BinaryTreeNode(leftChild)
            currentNode.left =leftNode
            q.put(leftNode)
        rightChild = levelorder[index]
        index += 1
        if rightChild != -1:
            rightNode = BinaryTreeNode(rightChild)
            currentNode.right =rightNode
            q.put(rightNode)
    return root

# Main
levelOrder = [int(i) for i in input().strip().split()]
root = buildLevelTree(levelOrder)
p = int(input())
q = int(input())
ans = checkCousins(root,p,q)
if ans is True:
    print('true')
else:
    print('false')
