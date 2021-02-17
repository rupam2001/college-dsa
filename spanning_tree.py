class Graph:

    class Edge:
        def __init__(self, src, dest, w):
            self.src = src
            self.dest = dest
            self.weight = w

    def __init__(self):
        self.EdgesList = []

    def appendEdge(self, src, dest, w):
        self.EdgesList.append(self.Edge(src, dest, w))

    def appendEdges(self, edgeList):
        for e in edgeList:
            self.EdgesList.append(e)

    def getNumVertices(self) -> int:
        return len(self.EdgesList)
    
    def makePriorityList(self, inplace=False):
        if inplace:
            self.EdgesList.sort(key=lambda edge : edge.weight)
        else:
            return sorted(self.EdgesList, key=lambda edge: edge.weight)

    def __repr__(self):
        stdout = ''
        for e in self.EdgesList:
            stdout += f'{e.src} -- {e.weight} -- {e.dest}\n'
        return stdout
    
    def createSpanningTree(self, edgesList=None):

        edgesList = edgesList if edgesList else self.EdgesList.copy()

        resTree = []





if __name__ == "__main__":

    graph = Graph()

    graph.appendEdges([
        graph.Edge('a', 'b', 4),
        graph.Edge('a', 'h', 8),
        graph.Edge('b', 'h', 11),
        graph.Edge('b', 'c', 8),
        graph.Edge('h', 'i', 7),
        graph.Edge('h', 'g', 1),
        graph.Edge('c', 'd', 7),
        graph.Edge('i', 'g', 6),
        graph.Edge('d', 'f', 14),
        graph.Edge('d', 'e', 9),
        graph.Edge('g', 'f', 2),
        graph.Edge('e', 'f', 10)
    ])
    graph.makePriorityList()
    print(graph)
    



