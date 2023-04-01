import numpy as np

def transportation_algorithm(cost_matrix, supplies, demands):
    """
    Implementation of the transportation algorithm.
    """
    # Step 1: Construct the transportation table
    table = np.zeros((len(supplies), len(demands)))
    for i in range(len(supplies)):
        for j in range(len(demands)):
            table[i][j] = cost_matrix[i][j]
    
    while True:
        # Step 2: Row and column reduction
        for i in range(len(supplies)):
            min_val = min(table[i])
            for j in range(len(demands)):
                table[i][j] -= min_val
        
        for j in range(len(demands)):
            min_val = min(table[:,j])
            for i in range(len(supplies)):
                table[i][j] -= min_val
        
        # Step 3: Find the cells with zero cost
        num_zeros = []
        for i in range(len(supplies)):
            for j in range(len(demands)):
                if table[i][j] == 0:
                    num_zeros.append((i, j, np.count_nonzero(table[i]) + np.count_nonzero(table[:,j]) - 2))
        
        if len(num_zeros) == 0:
            break
        
        # Step 4: Choose a cell and supply maximum amount
        row, col, _ = min(num_zeros, key=lambda x: (x[2], -np.sum(table[x[0], :]), -np.sum(table[:, x[1]])))
        min_supply = min(supplies[row], demands[col])
        table[row][col] += min_supply
        supplies[row] -= min_supply
        demands[col] -= min_supply
        
        # Step 5: Delete row or column if necessary
        if supplies[row] == 0:
            table = np.delete(table, row, 0)
            supplies = np.delete(supplies, row)
        elif demands[col] == 0:
            table = np.delete(table, col, 1)
            demands = np.delete(demands, col)
    
    # Step 6: Check for optimality
    while True:
        # Check for optimality
        u = np.zeros(len(supplies))
        v = np.zeros(len(demands))
        u[0] = 0
        
        while True:
            found = False
            for i in range(len(supplies)):
                for j in range(len(demands)):
                    if table[i][j] != 0 and (u[i] + v[j] == table[i][j] or (u[i] == 0 and v[j] == 0)):
                        u[i] = table[i][j] - v[j]
                        v[j] = table[i][j] - u[i]
                        found = True
            
            if not found:
                break
        
        # Step 7: If optimality is reached, return the result
        if np.allclose(np.dot(u, supplies) + np.dot(v, demands), np.sum(cost_matrix)):
            result = np.zeros(cost_matrix.shape)
            for i in range(len(supplies)):
                for j in range(len(demands)):
                    if table[i][j] != 0:
                        result[i][j] = table[i][j]
            return result
        else:
            # Step 2: Row and column reduction
            for i in range(len(supplies)):
                min_val = min(table[i])
                for j in range(len(demands)):
                    table[i][j] -= min_val
            
            for j in range(len(demands)):
                min_val = min(table[:,j])
                for i in range(len(supplies)):
                    table[i][j] -= min_val