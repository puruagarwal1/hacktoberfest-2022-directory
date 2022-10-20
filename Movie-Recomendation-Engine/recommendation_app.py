
import numpy as np
import pandas as pd
from sklearn.feature_extraction.text import CountVectorizer
from sklearn.neighbors import NearestNeighbors
from flask import Flask, request, render_template
import re


# this function will import dataset, create count matrix and create similarity score matrix
def create_model():
    #import dataset
    # Thid dataset is preprocessed tmdb_5000 dataset
    data = pd.read_csv('final_data.csv')
    # create count matrix
    cv = CountVectorizer()
    count_matrix = cv.fit_transform(data['combined_features'])
    # create similarity score matrix
    model = NearestNeighbors(metric='cosine', algorithm='brute')
    model.fit(count_matrix)
    return data, model, count_matrix


# this function will find movies related to choice entered and return list of 16 movies
# in which first movie will be the choice.
def recommend(choice):
    # this try-except block will check whether count matrix is created or not, if not
    # the it will call create_model() function.
    try:
        model.get_params()
    except:
        data, model, count_matrix = create_model()
        #distances,indices = model.kneighbors(count_matrix[choice_index],n_neighbors=11)

    # If movie name exactly matches with the name of movie in the data's title column
    # then this block will be executed.

    if choice in data['title'].values:
        choice_index = data[data['title'] == choice].index.values[0]
        distances, indices = model.kneighbors(
            count_matrix[choice_index], n_neighbors=16)
        movie_list = []
        for i in indices.flatten():
            movie_list.append(data[data.index == i]
                              ['original_title'].values[0].title())
        return movie_list

    # If no any movie name exactly matches with the title column of the data then,
    # in this block of code I am finding movie name which highly matches with movie name
    # entered by the user.

    elif (data['title'].str.contains(choice).any() == True):

        # getting list of similar movie names as choice.
        similar_names = list(str(s) for s in data['title'] if choice in str(s))
        # sorting the list to get the most matched movie name.
        similar_names.sort()
        # taking the first movie from the sorted similar movie name.
        new_choice = similar_names[0]
        print(new_choice)
        # getting index of the choice from the dataset
        choice_index = data[data['title'] == new_choice].index.values[0]
        # getting distances and indices of 16 mostly related movies with the choice.
        distances, indices = model.kneighbors(
            count_matrix[choice_index], n_neighbors=16)
        # creating movie list
        movie_list = []
        for i in indices.flatten():
            movie_list.append(data[data.index == i]
                              ['original_title'].values[0].title())
        return movie_list

    # If no name matches then this else statement will be executed.
    else:
        return "opps! movie not found in our database"


app = Flask(__name__)


@app.route("/")
def home():
    return render_template('main.html')


@app.route("/Search")
def search_movies():
    # getting user input
    choice = request.args.get('movie')
    # removing all the characters except alphabets and numbers.
    choice = re.sub("[^a-zA-Z1-9]", "", choice).lower()
    # passing the choice to the recommend() function
    movies = recommend(choice)
    # if rocommendation is a string and not list then it is else part of the
    # recommend() function.
    if type(movies) == type('string'):
        return render_template('movie_list.html', movie=movies, s='opps')
    else:
        return render_template('movie_list.html', movie=movies)


if __name__ == "__main__":
    app.run(debug=False)
