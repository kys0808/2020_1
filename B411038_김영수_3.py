#1

def make_album(artist, title):
    return {'artist':artist, 'title':title}

print(make_album("BTS","Map of the Soul:7"))

#2

def make_album2(artist, title, num_tracks=''):
    album = {'artist':artist, 'title':title}
    if(num_tracks):
        album['num_tracks'] = num_tracks
    return album

print(make_album2("BTS", "Map of the Soul:7"))
print(make_album2("BTS", "Map of the Soul:7", 3))

# 3
def build_profile(first, last, **user_info):
    return {'first_name': first, 'last_name': last,
            'address':user_info['address_num'], 'phone': user_info['phone_num']}

print(build_profile('영수','김',address_num= '서울', phone_num= '010-2734-0582'))

# 4
class Restaurant:
    def __init__(self, name, cuisine):
        self.name = name
        self.cuisine = cuisine
        self.number_served = 0

    def get_number_served(self):
        return self.number_served
    def set_number_served(self, num):
        self.number_served = num
    def increment_number_served(self, inc):
        self.number_served += inc

bon = Restaurant("Bon Glorno","Italian")
bon.number_served = 4
print(bon.get_number_served())

bon.set_number_served(8)
print(bon.get_number_served())

bon.increment_number_served(6)
print(bon.get_number_served())

#5

class IceCreamStand(Restaurant):
    def __init__(self, name, cuisine, flavors = ['vanilla', 'strawberry', 'chocolate']):
        self.flavors = flavors
        super().__init__(name, cuisine)

    def show_flavors(self):
        return self.flavors

young = IceCreamStand("Young Su","Italian",'vanilla')
print(young.show_flavors())
