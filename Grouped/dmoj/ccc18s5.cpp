// connections can be sorted by smallest cost
// the edges can be added in non-decreasing order of cost
// isnt this just MST?
// but I have to be careful about the number of edges I compute...
// nvm only P edges 
// so just MST where I label all cities with unique ID: planetId*M + cityNum
// and just cost of graph - cost of MST