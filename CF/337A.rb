g=->{gets.split.map &:to_i};n,m=g[];a=g[].sort;p a[n-1...m].zip(a).map{|i,j|i-j}.min
