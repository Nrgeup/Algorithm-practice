class Node(object):
    def __init__(self, c):
        self.char = c
        self.child = []
        self.if_end = False


class Trie(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.head = Node('')

    def insert(self, word):
        """
        Inserts a word into the trie.
        :type word: str
        :rtype: None
        """
        last_node = self.head
        for c in word:
            flag = True
            for i in range(len(last_node.child)):
                if last_node.child[i].char == c:
                    flag = False
                    break
            if flag:
                new_node = Node(c)
                last_node.child.append(new_node)
                last_node = new_node
            else:
                last_node = last_node.child[i]
        last_node.if_end = True

    def search(self, word):
        """
        Returns if the word is in the trie.
        :type word: str
        :rtype: bool
        """
        last_node = self.head
        for c in word:
            flag = True
            for i in range(len(last_node.child)):
                if last_node.child[i].char == c:
                    flag = False
                    break
            if flag:
                return False
            last_node = last_node.child[i]
        return last_node.if_end

    def startsWith(self, prefix):
        """
        Returns if there is any word in the trie that starts with the given prefix.
        :type prefix: str
        :rtype: bool
        """
        last_node = self.head
        for c in prefix:
            flag = True
            for i in range(len(last_node.child)):
                if last_node.child[i].char == c:
                    flag = False
                    break
            if flag:
                return False
            last_node = last_node.child[i]
        return True

# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)


