import requests
r = requests.get("https://www.douyin.com/user/MS4wLjABAAAAnzGn934eyJ8AVReosWgZVKtI23nRC2oLKu-Eok9xmqwhtautV5b0K3B4z4oGYaut?from_tab_name=main&vid=7516146772508806463")
data = r.json()
print(data)
