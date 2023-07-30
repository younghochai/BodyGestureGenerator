import os
import numpy as np
import json
from json import JSONEncoder
# np.set_printoptions(threshold=sys.maxsize)

root_file_path = 'TotalCapture/s3/'
npz_file_name = ['acting1_stageii.npz','acting2_stageii.npz','acting3_stageii.npz',
                 'freestyle1_stageii.npz', 'freestyle2_stageii.npz', 'freestyle3_stageii.npz',
                 'rom1_stageii.npz', 'rom2_stageii.npz', 'rom3_stageii.npz',
                 'walking1_stageii.npz', 'walking2_stageii.npz', 'walking3_stageii.npz']

temp_name = 'walking1_stageii'

# npz 파일 경로
npz_file_path = root_file_path + temp_name + '.npz'


''' s1 actring1~3 키 값 목록
gender
surface_model_type
mocap_frame_rate
mocap_time_length
markers_latent
latent_labels
markers_latent_vids
trans
poses
betas
num_betas
root_orient
pose_body
pose_hand
pose_jaw
pose_eye
markers
labels
markers_obs
labels_obs
markers_sim
marker_meta
num_markers
'''
text = "mocap_time_length"

# npz 파일 열기
npz_data = np.load(npz_file_path, allow_pickle=True)

a2 = npz_data['root_orient']
b2 = npz_data['pose_body']

result = np.concatenate((a2,b2),axis=1)

lst = npz_data.files
# for key in lst: # 파일 목록 불러오기(딕셔너리)
#    print(key)
#    print(npz_data[key])
print(text)
print(npz_data[text])
# npz_data_len = npz_data[text]
# print(len(npz_data_len[0]))

gender_data = npz_data['gender']
gender_data = np.array([gender_data])
surface_data = npz_data['surface_model_type']
surface_data = np.array([surface_data])
frame_data = npz_data['mocap_frame_rate']
frame_data = np.array([frame_data])
time_data = npz_data['mocap_time_length']
time_data = np.array([time_data])

text2 = 'concat_root_body_pose'
# .csv 파일 변환
# np.savetxt(temp_name +'_'+text2+'.csv', result, delimiter=",") #, fmt='%s'
# np.savetxt('acting1_stageii'+'_'+text+'.csv', npz_data[text], delimiter=",") #, fmt='%s'
# np.savetxt('acting1_stageii'+'_'+text+'.csv', npz_data[text], fmt='%s') #, fmt='%s'
# np.savetxt('acting1_stageii_time.csv', time_data, fmt='%s')  # 문자열 포멧으로 변환

# 데이터 추출
# data_dict = {}
# for key in npz_data.keys():
#     data_dict[key] = npz_data[key].tolist()
#
# # JSON 변환
# json_data = json.dumps(data_dict, default=lambda x: x.tolist())
#
# # JSON 파일 저장
# json_file_path = "output.json"
# with open(json_file_path, "w") as json_file:
#     json_file.write(json_data)
#
# print("Saved JSON data to", json_file_path)



# class NumpyArrayEncoder(JSONEncoder):
#     def default(self, obj):
#         if isinstance(obj, np.ndarray):
#             return obj.tolist()
#         return JSONEncoder.default(self, obj)


# npz 파일에 저장된 데이터 확인
# for array_name in npz_data.files:
#     array_data = npz_data[array_name]
#     encodedNumpyData = json.dumps(array_data, cls=NumpyArrayEncoder)
#     print("Printing JSON serialized Numpy array")
#     print(encodedNumpyData)

    # print("Array Name:", array_name)
    # print("Array Data:")
    # print(array_data)

# npz_file_path = 'your_npz_file.npz'
#
# # .npz 파일 로드
# npz_data = np.load(npz_file_path)
#
# # .json 파일 이름 생성
# json_file_path = os.path.splitext(npz_file_path)[0] + '.json' # [0]:파일 이름,[1]:확장자
#
# # 배열을 JSON 형식으로 변환
# json_data = json.dumps(npz_data)
#
# # .json 파일 저장
# with open(json_file_path, "w") as json_file:
#     json_file.write(json_data)

# folder_path = 'your_folder_path'  # 읽어올 폴더 경로
# npz_files = [file for file in os.listdir(folder_path) if file.endswith('.npz')]  # .npz 파일 목록 가져오기
#
# for npz_file in npz_files:
#     npz_file_path = os.path.join(folder_path, npz_file)  # 폴더 경로와 파일명 합치기
#
#     # .npz 파일 로드
#     npz_data = np.load(npz_file_path)
#
#     # TODO: 원하는 작업 수행
#     # 예시: 배열 출력
#     print(npz_data['array1'])


