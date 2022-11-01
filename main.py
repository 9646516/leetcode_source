import requests
import os
import json
import time
import threading

SESSION = 'eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJfYXV0aF91c2VyX2lkIjoiMTQ5NTMyNSIsIl9hdXRoX3VzZXJfYmFja2VuZCI6ImFsbGF1dGguYWNjb3VudC5hdXRoX2JhY2tlbmRzLkF1dGhlbnRpY2F0aW9uQmFja2VuZCIsIl9hdXRoX3VzZXJfaGFzaCI6Ijg1MzVkMmEwMjIwNzY2ZjA1YzNkYjY3MjM3OGVhMTcxMDIzNDBjOTk0MmJhYjJlNDhkZGRiOWU1NjdjZDBjYzgiLCJpZCI6MTQ5NTMyNSwiZW1haWwiOiJ6eXE4NTVAZ21haWwuY29tIiwidXNlcm5hbWUiOiI5NjQ2NTE2IiwidXNlcl9zbHVnIjoiOTY0NjUxNiIsImF2YXRhciI6Imh0dHBzOi8vYXNzZXRzLmxlZXRjb2RlLmNuL2FsaXl1bi1sYy11cGxvYWQvdXNlcnMvOTY0NjUxNi9hdmF0YXJfMTY2NTgzMDMxMy5wbmciLCJwaG9uZV92ZXJpZmllZCI6dHJ1ZSwiX3RpbWVzdGFtcCI6MTY2NzI4ODMwMi40OTY3NDI3LCJleHBpcmVkX3RpbWVfIjoxNjY5ODM0ODAwLCJ2ZXJzaW9uX2tleV8iOjAsImxhdGVzdF90aW1lc3RhbXBfIjoxNjY3Mjg4NDU5fQ.Xb676GMGF-WrlZv1KAx9ywPQUXn3dhzcS5o_ESZ1f_0'
# os.environ['http_proxy'] = "http://127.0.0.1:23334"
# os.environ['https_proxy'] = "http://127.0.0.1:23334"

url = 'https://leetcode.cn/graphql/'
s = requests.Session()
s.cookies.set("LEETCODE_SESSION", SESSION)

s.headers = {
    'Origin': 'https://leetcode.cn',
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/107.0.0.0 Safari/537.36 Edg/107.0.1418.26',
    'content-type': 'application/json'
}
s.get('https://leetcode.cn/accounts/login/')

res = s.post(url, data=json.dumps({
    "operationName": "nojGlobalData",
    "variables": {},
    "query": "query nojGlobalData {\n  siteRegion\n  chinaHost\n  websocketUrl\n}\n"
}).encode('utf8'))
print(res.text)


def get_page(page):
    data = {
        "operationName": "userProfileQuestions",
        "variables": {
            "status": "ACCEPTED",
            "skip": page * 20,
            "first": 20,
            "sortField": "LAST_SUBMITTED_AT",
            "sortOrder": "DESCENDING",
            "difficulty": []
        },
        "query": "query userProfileQuestions($status: StatusFilterEnum!, $skip: Int!, $first: Int!, $sortField: SortFieldEnum!, $sortOrder: SortingOrderEnum!, $keyword: String, $difficulty: [DifficultyEnum!]) {\n  userProfileQuestions(status: $status, skip: $skip, first: $first, sortField: $sortField, sortOrder: $sortOrder, keyword: $keyword, difficulty: $difficulty) {\n    totalNum\n    questions {\n      translatedTitle\n      frontendId\n      titleSlug\n      title\n      difficulty\n      lastSubmittedAt\n      numSubmitted\n      lastSubmissionSrc {\n        sourceType\n        ... on SubmissionSrcLeetbookNode {\n          slug\n          title\n          pageId\n          __typename\n        }\n        __typename\n      }\n      __typename\n    }\n    __typename\n  }\n}\n"
    }
    res = s.post(url, data=json.dumps(data).encode('utf8'))
    res = json.loads(res.text)['data']['userProfileQuestions']['questions']
    return res


def get_single(F):
    data = {
        "operationName": "progressSubmissions",
        "variables": {
            "offset": 0,
            "limit": 100,
            "questionSlug": F['titleSlug']
        },
        "query": "query progressSubmissions($offset: Int, $limit: Int, $lastKey: String, $questionSlug: String) {\n  submissionList(offset: $offset, limit: $limit, lastKey: $lastKey, questionSlug: $questionSlug) {\n    lastKey\n    hasNext\n    submissions {\n      id\n      timestamp\n      url\n      lang\n      runtime\n      __typename\n    }\n    __typename\n  }\n}\n"
    }
    res = s.post(url, data=json.dumps(data).encode('utf8'))
    res = json.loads(res.text)['data']['submissionList']['submissions']
    select = None
    for i in res:
        if "ms" in i['runtime']:
            select = i
            break
    if select is None:
        return None
    # print(select)
    data = {
        "operationName": "mySubmissionDetail",
        "variables": {
            "id": select['id']
        },
        "query": "query mySubmissionDetail($id: ID!) {\n  submissionDetail(submissionId: $id) {\n    id\n    code\n    runtime\n    memory\n    rawMemory\n    statusDisplay\n    timestamp\n    lang\n    isMine\n    passedTestCaseCnt\n    totalTestCaseCnt\n    sourceUrl\n    question {\n      titleSlug\n      title\n      translatedTitle\n      questionId\n      __typename\n    }\n    ... on GeneralSubmissionNode {\n      outputDetail {\n        codeOutput\n        expectedOutput\n        input\n        compileError\n        runtimeError\n        lastTestcase\n        __typename\n      }\n      __typename\n    }\n    submissionComment {\n      comment\n      flagType\n      __typename\n    }\n    __typename\n  }\n}\n"
    }
    res0 = s.post(url, data=json.dumps(data).encode('utf8')).text
    res = json.loads(res0)['data']['submissionDetail']
    if res is None:
        return False
    ret = open("./src/{}.cpp".format(F['frontendId']), "w", encoding='utf8', newline='\n')
    for i in ["id", "runtime", "memory"]:
        ret.write("// {}:{}\n".format(i, res[i]))
    for i in ["title", "translatedTitle", "questionId"]:
        ret.write("// {}:{}\n".format(i, res['question'][i]))

    tt = time.strftime("%Y-%m-%d %H:%M:%S", time.localtime(res['timestamp']))
    ret.write("// time:{}\n".format(tt))
    ret.write("\n")
    ret.write(res['code'])
    ret.close()
    return True


mutex = threading.Lock()
Q = []
tot = 0


def worker():
    done = 0
    while len(Q) != 0:
        print("{}/{}".format(len(Q), tot))
        F = Q.pop()
        res = get_single(F)
        if not res:
            Q.append(F)
            time.sleep(10)
        else:
            done += 1
            if done % 10 == 0:
                time.sleep(1)


for i in range(100000):
    F = get_page(i)
    if len(F) == 0:
        break
    for j in F:
        Q.append(j)
        print(j)
if not os.path.exists("./src"):
    os.mkdir("./src")
tot = len(Q)
worker()
