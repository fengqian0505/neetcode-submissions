class WordDictionary:

    def __init__(self):
        self.root = {}
        
    def addWord(self, word: str) -> None:
        node = self.root
        for c in word:
            if c not in node:
                node[c] = {}
            
            node = node[c]
        
        node['#'] = True

    def search(self, word: str) -> bool:
        def dfs(node, word, idx):
            if idx == len(word):
                return '#' in node

            c = word[idx]
            if c != '.':
                if c in node:
                    return dfs(node[c], word, idx+1)
            else:
                for key in node.keys():
                    if key != '#':
                        if dfs(node[key], word, idx+1):
                            return True
            
            return False

        return dfs(self.root, word, 0)
        
