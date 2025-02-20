import numpy as np
import matplotlib.pyplot as plt
from sklearn.datasets import make_blobs
from sklearn.cluster import KMeans

if __name__ == "__main__":
    
    np.random.seed(20)

    X,_ = make_blobs(n_samples = 500,n_features = 2,centers = 3,random_state = 23)
    # X = np.random.rand(500, 2)  # The rand function will generate very randonly distributed data
    
    # print (X)

    # Number of clusters
    k = 3
    # Number of iterations. Not used in this algorithm implementation. But is a parameter for the KMean class.
    n_iter = 100
    # Run k-mean
    kmeans = KMeans(n_clusters=k, random_state=0, n_init="auto")
    kmeans.fit(X)
    centers = kmeans.cluster_centers_
    print("Cluster centers by sklearn.KMeans:\n", centers)
    

    # self implementation. The consistency is pretty good
    #create three random centroids
    centroids = np.random.rand(k, 2)

    #group data points to the closest centroid
    clusters = {}
    for i in range(k):
        clusters[i] =  {"center": centroids[i], "points": []}

    for pt in X:
        dists = []
        for i in range(k):
            dist = np.linalg.norm(centroids[i] - pt, axis=0)
            dists.append(dist)
        closest_centroid = np.argmin(dists)
        clusters[closest_centroid]["points"].append(pt)

    #upgrade the centroids to the mean of the group
    for i in range(k):
        clusters[i]["center"] = np.mean(clusters[i]["points"], axis=0)

    print("Cluster centers by randomly generated seeds:")
    for i in range(k):
        print(clusters[i]["center"])