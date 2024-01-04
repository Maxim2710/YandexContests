package main

import (
	"fmt"
)

// Ваш код здесь

type BinaryTreeNode struct {
	value int
	left  *BinaryTreeNode
	right *BinaryTreeNode
}

func NewBinaryTreeNode(value int) *BinaryTreeNode {
	var tree BinaryTreeNode
	tree.value = value
	tree.left = nil
	tree.right = nil
	return &tree
}

func (t *BinaryTreeNode) insertNode(value int) {
	if value < t.value {
		if t.left == nil {
			t.left = NewBinaryTreeNode(value)
		} else {
			t.left.insertNode(value)
		}
	} else {
		if t.value == value {
			return
		}

		if t.right == nil {
			t.right = NewBinaryTreeNode(value)
		}

		t.right.insertNode(value)
	}
}

func (t *BinaryTreeNode) getMax() *BinaryTreeNode {
	if t == nil {
		return nil
	}

	if t.right == nil {
		return t
	}

	return t.right.getMax()
}

func (t *BinaryTreeNode) removeNode(value int) *BinaryTreeNode {
	if t == nil {
		return nil
	} else if value < t.value {
		t.left = t.left.removeNode(value)
	} else if value > t.value {
		t.right = t.right.removeNode(value)
	} else {
		if t.left == nil || t.right == nil {
			if t.left == nil {
				t = t.right
			} else {
				t = t.left
			}
		} else {
			max_cur := t.left.getMax()
			t.value = max_cur.value
			t.left = t.left.removeNode(max_cur.value)
		}
	}

	return t
}

func (t *BinaryTreeNode) findNode(value int) *BinaryTreeNode {
	if t == nil {
		return nil
	}

	if t.value == value {
		return t
	}

	if value < t.value {
		return t.left.findNode(value)
	}

	return t.right.findNode(value)
}

func (t *BinaryTreeNode) String() string {
	var listWithInfo []*BinaryTreeNode
	lineTree := ""
	listWithInfo = append(listWithInfo, t)

	for len(listWithInfo) > 0 {
		lineTree += fmt.Sprintf("%d", listWithInfo[0].value) + " "
		if listWithInfo[0].left != nil {
			listWithInfo = append(listWithInfo, listWithInfo[0].left)
		}

		if listWithInfo[0].right != nil {
			listWithInfo = append(listWithInfo, listWithInfo[0].right)
		}

		listWithInfo = listWithInfo[1:]
	}

	return lineTree
}

func main() {
	var count int
	fmt.Scan(&count)

	var root *BinaryTreeNode
	for count > 0 {
		var command string
		var value int
		fmt.Scan(&command, &value)

		if command == "insert" {
			if root == nil {
				root = NewBinaryTreeNode(value)
			}
			root.insertNode(value)
		} else if command == "remove" {
			root = root.removeNode(value)
		} else if command == "find" {
			fmt.Println(root.findNode(value))
		}

		count--
	}
}
