class TreeNode {
    int value;
    TreeNode left, right;

    public TreeNode(int value) {
        this.value = value;
        left = right = null;
    }
}

public class BinaryTreeDFS {
    // Recursive DFS
    static void dfs(TreeNode node) {
        if (node == null) {
            return;
        }

        System.out.print(node.value + " ");

        dfs(node.left);

        dfs(node.right);
    }

    public static void main(String[] args) {
        // Create a sample binary tree
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.left.left = new TreeNode(4);
        root.left.right = new TreeNode(5);
        root.right.left = new TreeNode(6);
        root.right.right = new TreeNode(7);

        System.out.println("Depth-First Search (DFS) on Binary Tree:");
        dfs(root);
    }
}
